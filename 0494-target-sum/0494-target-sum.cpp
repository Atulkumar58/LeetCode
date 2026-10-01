class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int , int> mp; // sum-> freq
        mp[0]=1;
        for(int i: nums){
            unordered_map<int, int> temp;
            for(auto& it: mp){
                temp[it.first + i]+= it.second;
                temp[it.first - i]+= it.second;
            }

            mp= temp;
        }

        return mp[target];
    }
};