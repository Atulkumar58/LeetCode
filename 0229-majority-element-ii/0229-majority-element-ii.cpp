class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int>hash;
        int n= nums.size();
        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }

        int maxvalue= n/3;
        vector<int> ans;
        for(auto t: hash){
            if(maxvalue < t.second){
                ans.push_back(t.first);
            }
        }
        return ans;
    }
};
    