class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n);

        int ans=0;
        for(int i=0; i<n; i++){
            int a= (i>1) ? dp[i-2] : 0;
            int b= (i > 2) ? dp[i-3]:0;
            dp[i]= nums[i]+ max(a, b);
            ans= max(ans, dp[i]);
        }
        return ans;
    }
};