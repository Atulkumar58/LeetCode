class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans= nums[0];
        int n= nums.size();
        int s=0, e= nums.size()-1;
        if(nums[0] < nums[e]) return nums[0];
        while(s <= e){
            int mid= (s+e)/2;
            // cout<<mid<<" ";
            if(s!= e && nums[s] == nums[e]){
                ans= min(ans, nums[s]);
                s++,e--;}
            else if(nums[mid] <= nums[e]){
                ans= min(ans, nums[mid]);
                e= mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};