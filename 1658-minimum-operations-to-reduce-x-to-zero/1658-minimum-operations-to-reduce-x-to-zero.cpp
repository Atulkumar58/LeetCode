class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        int sum= accumulate(nums.begin(), nums.end(), 0);
        int windowsum= sum-x;
        if(windowsum < 0) return  -1;
        int tempsum=0;
        int i=0, j=0;
        int ans= INT_MAX;
        while(true){
            if(tempsum < windowsum){
                if(j>=n) break;
                tempsum+= nums[j++];
            }
            else{
                if(i>=n) break;
                tempsum -= nums[i++];
            }

            if(tempsum == windowsum){
                ans= min(ans, i+n-j);
            }
        }
        return ans==INT_MAX ? -1: ans;
    }
};