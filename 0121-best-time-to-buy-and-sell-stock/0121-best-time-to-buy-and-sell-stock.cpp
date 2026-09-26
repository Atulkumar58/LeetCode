class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest=prices[0];
        int ans=0;
        for(int i=1; i<prices.size(); i++){
            ans= max(ans, prices[i]-lowest);
            lowest= min(lowest, prices[i]);
        }
        return ans;
    }
};