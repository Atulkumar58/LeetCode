class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51, 0);
        int ans=-1;
        for(int i: nums) {freq[i]++; ans= max(ans, i);}
        if(nums.size() == k) return ans;

        int maxi=-1;
        for(int i=0; i<=50; i++){
            if(freq[i]==1) maxi= max(maxi, i);
        }
        if(k==1) return maxi;
        maxi=-1;
        if(freq[nums[0]] == 1){
            maxi= max(maxi, nums[0]);
        }
        if(freq[nums.back()] == 1) maxi= max(maxi, nums.back());
        return maxi;
    }
};