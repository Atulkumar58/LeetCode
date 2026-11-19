class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans= INT_MAX;
        int j= nums.size()-1;
        for(int idx=2; idx>=0 ; idx--){
            ans= min(ans, nums[j]-nums[idx]);
            j--;
        }
        return ans;
    }
};