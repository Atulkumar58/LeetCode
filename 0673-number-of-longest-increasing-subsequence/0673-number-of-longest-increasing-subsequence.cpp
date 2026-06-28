class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<pair<int,int>> dp(n);
        for(int i=0;i<n; i++){
            int length= 0, count=0;
            for(int j= i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    if(length == dp[j].first){
                        count += dp[j].second;
                    }
                    else if(length < dp[j].first){
                        length= dp[j].first;
                        count = dp[j].second;
                    }
                }
            }
            if(count == 0) count++;
            dp[i] = {length+1, count};
            
        }
        int minlength = 0;
        int freq = 0;
        for(int i=0; i<n; i++){
            // cout<<dp[i].first<<" "<<dp[i].second<<endl;
            if(minlength < dp[i].first){
                minlength = dp[i].first;
                freq = dp[i].second;
            }
            else if(minlength == dp[i].first){
                freq += dp[i].second;
            }
        }
        return freq;
    }
};