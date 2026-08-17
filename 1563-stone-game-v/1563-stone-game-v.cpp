class Solution {
public:
    vector<vector<int>>dp;
    vector<int>stoneValue;
    int calculate(int i, int j, int totalsum){
        if(i==j){
            dp[i][j]=0;
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        int sum=0;
        int ans=0;
        for(int idx= i; idx<j; idx++){
            sum+= stoneValue[idx];

            if(sum <= totalsum-sum){
                ans= max(ans, sum+ calculate(i, idx, sum));
            }
            if(sum >= totalsum - sum){
                ans= max(ans, totalsum-sum + calculate(idx+1, j, totalsum-sum));
            }
        }
        dp[i][j]= ans;
        return ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n= stoneValue.size();
        this->stoneValue= stoneValue;
        int totalsum= accumulate(stoneValue.begin(), stoneValue.end(), 0);
        dp.resize(n+1, vector<int>(n+1, -1));
        return calculate(0, n-1, totalsum);
    }
};