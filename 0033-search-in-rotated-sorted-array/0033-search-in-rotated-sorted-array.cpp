class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0, e= nums.size()-1;
        while(s<=e){
            int mid= (s+e)/2;
            // cout<<s<<" "<<e<<" "<<mid<<endl;
            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[s]){
                //first half
                if(target < nums[mid] && target >= nums[s]){
                    e= mid-1;
                }
                else{
                    s= mid+1;
                }
            }else{
                //second half
                if(target > nums[mid] && target< nums[s]){
                    s= mid+1;
                }else e= mid-1;
            }
            
        }
        return -1;
    }
};