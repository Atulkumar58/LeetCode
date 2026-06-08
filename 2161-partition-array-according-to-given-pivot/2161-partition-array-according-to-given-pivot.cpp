class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        vector<int> ans;
        int c=0;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                c++;
            }
        }
        while(c--){
            ans.push_back(pivot);
        }
        for(int i=0; i<n; i++){
            if(nums[i] > pivot){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};