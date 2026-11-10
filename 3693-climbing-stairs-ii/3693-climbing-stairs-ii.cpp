class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> mincost(n,INT_MAX);
        mincost[n-1]= costs.back();
        for(int j=n-1; j>=0; j--){
            for(int k= j-1; k>=0 && k>=j-3; k--){
                mincost[k]= min(mincost[k], (int)(mincost[j]+pow(j-k, 2)+ costs[k]));
            }
            // cout<<mincost[j]<<" ";
        }

        int ans=INT_MAX;
        for(int i=0; i<n && i<3; i++){
            ans= min(ans, (int)(mincost[i]+ pow(i+1, 2)));
        }
        return ans;
    }
};