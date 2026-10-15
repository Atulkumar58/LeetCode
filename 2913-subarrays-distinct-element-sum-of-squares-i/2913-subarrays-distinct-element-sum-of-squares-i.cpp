class Solution {
public:
    int sumCounts(vector<int>& nums) {
        set<int>s;
        int n= nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            s.clear();
            for(int j=i; j<n; j++){
                s.insert(nums[j]);
                ans+= pow(s.size(), 2);
            }
        }
        return ans;
    }
};