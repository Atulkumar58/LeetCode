class Solution {
public:
    static bool custom (const pair<int, int>&a, const pair<int, int>&b){
        if((a.second*(a.first + b.first) + b.second*b.first) < (b.second*(a.first+b.first)+a.first*a.second)){
            return 1;
        }
        return 0;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n= damage.size();
        vector<pair<int, int>> p(n);
        long long sum=0;
        for(int i=0; i<n; i++){
            p[i]={damage[i], (health[i]-1)/power+1};
            sum+= damage[i];
        }

        sort(p.begin(), p.end(), custom);
        long long ans=0;
        for(auto& i: p){
            // cout<<i.first<<" "<<i.second<<endl;
            ans+= (sum*i.second);
            sum-= i.first;
        }
        return ans;
    }
};