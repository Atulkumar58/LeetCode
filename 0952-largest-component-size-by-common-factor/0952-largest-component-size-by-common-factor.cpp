class Solution {
public:
    vector<int> primes;
    vector<bool> pr;
    void pre(){
        for(int i=2; i*i<=1e5; i++){
            for(int j= i*i; j<=1e5; j+=i){
                pr[j]=0;
            }
        }
        for(int i=2; i<1e5; i++){
            if(pr[i]) primes.push_back(i);
        }
    }
    vector<int> prime_parent;
    unordered_map<int,int> mp; //prime -> size
    int ultimateparent(int idx){
        if(idx== prime_parent[idx] || prime_parent[idx] == -1) return idx;

        int i= ultimateparent(prime_parent[idx]);
        prime_parent[idx]= i;
        return i;
    }
    int join (int idx1, int idx2){
        if(idx1 == -1) return idx2;
        // cout<<idx1<<" "<<idx2<<" ";
        idx1= ultimateparent(idx1);
        idx2= ultimateparent(idx2);
        // cout<<idx1<<" "<<idx2<<endl;
        if(idx1 == idx2) return idx1;

        prime_parent[idx2]= idx1;
        mp[idx1]+= mp[idx2];
        // cout<<"join"<<primes[idx1]<<" "<<mp[idx1];
        return idx1;
    }
    void findfactors(int n){
        if(n==1) return;
        int idx=0;
        int head=-1;
        // cout<<n<<" ";
        // cout<<endl;
        while(n > 1){
            int num= primes[idx];
            // if(pr[n]) num= n;
            if(n%num == 0) {
                // cout<<"idx"<<idx<<" ";
                head= join(head, idx);
                n/=num;
            }
            else idx++;
        }
        mp[ultimateparent(head)]++;
        // cout<<"size"<<mp[head]<<endl;
    }

    int largestComponentSize(vector<int>& nums) {
        primes.clear();
        pr.resize(1e5, 1);
        pre();
    
        prime_parent.resize(primes.size(), -1);
        mp.clear();
        int ans=0;
        for(int i:nums){
            findfactors(i);
            if(i==1) ans=1;
        }
        
        for(auto [a,b] : mp){
            ans= max(ans, b);
        }
        return ans;
    }
};