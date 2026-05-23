class Solution {
public:
    bool check(vector<int>& nums) {
       int a=0;
       int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                a++;
            }

        }
       if((a==1 && nums[0]>= nums[n-1]) || a==0){
        return true;
       }else {
        return 0;
       }
    }
};