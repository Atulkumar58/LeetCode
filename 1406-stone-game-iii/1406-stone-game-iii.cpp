class Solution {
public:
    vector<int> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        int n= stoneValue.size();
        dp.resize(n+3, INT_MIN);
        dp[n]= 0;
        for(int i= n-1; i>=0; i--){
            int sum=0;

            for(int j=0; j<3 && i+j < n; j++){
                sum+= stoneValue[i+j];
                dp[i]= max(dp[i], sum - dp[i+j+1]);
            }
        }

        if(dp[0] == 0) return "Tie";
        else if(dp[0] > 0) return "Alice";
        else return "Bob";
    }
};