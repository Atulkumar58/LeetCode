class Solution {
public:
    //revise easy yet tricky
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++){
            int best=0, maxv= 0;
            for(int j= i; j>0 && j>i-k; j--){
                maxv= max(maxv, arr[j-1]);
                best= max(best, maxv * (i-j+1) + dp[j-1]);
            }
            dp[i]= best;
            // cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};