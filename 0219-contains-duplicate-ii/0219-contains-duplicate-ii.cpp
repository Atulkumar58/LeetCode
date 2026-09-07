class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, bool>m;
        int i=0, j=0;
        while(j<nums.size()){
            if(j-i <= k){
                if(m[nums[j]]){
                    return true;
                }else{
                    m[nums[j]]=1;
                    j++;
                }
            }
            else{
                m[nums[i]]=0;
                i++;
            }
        }

        return false;
    }
};