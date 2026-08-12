class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n, 0);
        map<int, vector<int>>mp;
        int ans=0;
        int last=-1;
        for(int i=0;  i<n; i++){
            auto& t= mp[nums[i]];
            t.push_back(i);
            if(t.size() > k){
                last= max(last, t[t.size()- k-1]);
            }
            // cout<<last<<" ";
            ans= max(ans, i- last);
        }
        return ans;
    }
};