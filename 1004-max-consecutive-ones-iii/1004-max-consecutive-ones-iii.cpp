class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> arr;
        arr.push_back(-1);
        int i=0;
        while(i< nums.size()){
            if(nums[i]==0) arr.push_back(i);
            i++;
        }
        arr.push_back(nums.size());
        int ans=0;
        
        if(k >= arr.size()-2) return nums.size();
        for(int i=0; i< arr.size()-k-1; i++){
            ans= max(ans, arr[i+k+1]- arr[i]-1);
        }
        
        return ans;
    }
};