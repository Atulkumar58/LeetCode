class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, int> mp;
        int ans=0;
        int i=0, j=0;
        while(j<n){
            if(mp[nums[j]] >= k){
                mp[nums[i++]]--;
            }
            else mp[nums[j++]]++;

            ans= max(ans, j-i);
        }
        return ans;
    }
};