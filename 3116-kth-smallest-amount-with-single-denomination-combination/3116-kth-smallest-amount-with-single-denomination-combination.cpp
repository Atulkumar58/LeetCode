class Solution {
public:
    long long lcm(long long a, long long b){
        return a*b/gcd(a, b);
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end());
        vector<long long> pos;
        vector<long long> neg;
        int n= coins.size();
        for(int i=0; i<n; i++){
            vector<long long> p= pos;
            vector<long long> ne = neg;
            p.push_back(coins[i]);

            for(int j: neg){
                p.push_back(lcm(j, coins[i]));
            }
            for(int j: pos) ne.push_back(lcm(j, coins[i]));

            sort(p.begin(), p.end());
            sort(ne.begin(), ne.end());
            pos.clear();
            neg.clear();

            int x=0, y=0;
            while(x< p.size() && y<ne.size()){
                if(p[x] == ne[y]) x++, y++;
                else if(p[x] < ne[y]){
                    pos.push_back(p[x]);
                    x++;
                }
                else{
                    neg.push_back(ne[y]);
                    y++;
                }
            }

            while(x<p.size()){
                pos.push_back(p[x]); x++;
            }
            while(y<ne.size()){
                neg.push_back(ne[y]); y++;
            }
            // cout<<i<<" " <<coins[i]<<endl;
            // for(int i: pos) cout<<i<<" "; cout<<endl;
            // for(int i: neg) cout<<i<<" "; cout<<endl;
            // cout<<endl;
        }
        

        //BINARY Search

        long long s=1, e=LLONG_MAX;
        long long ans=0;
        while(s<=e){
            long long mid= s+(e-s)/2;
            long long sum=0;
            int i=0, j=0;
            while(i<pos.size()){
                while(j<neg.size() && sum >= mid/neg[j]){

                    sum-= (mid/neg[j]);
                    j++;
                }

                sum+= (mid/pos[i]);
                i++;
            }

            if(sum >= k){
                if(sum == k){
                    bool possible= false;
                    for(int i:coins){
                        if(mid%i ==0){
                            possible=1;
                            break;
                        }
                    }
                    if(possible){
                        ans= mid;
                    }
                }
                e= mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};