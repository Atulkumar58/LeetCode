class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        for(int i: nums) maxi= max(maxi, i);

        int length=1;
        int curr=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==maxi && nums[i] == nums[i-1]){
                curr++;
                length= max(length, curr);
            }else {
                curr=1;
            }
        }
        return length;
    }
};