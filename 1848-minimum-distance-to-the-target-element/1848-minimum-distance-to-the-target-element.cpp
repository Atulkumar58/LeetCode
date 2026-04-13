class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n= nums.size();
        int i= 0;
        while(start-i >=0 || start+i < n){
            if(start-i >= 0 && nums[start-i] == target) return i;
            if(start+i <= n && nums[start+i] == target) return i;
            i++;
        }
        return -1;
    }
};