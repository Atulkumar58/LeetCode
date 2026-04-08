class Solution {
public:
    const int mod= 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(vector<int>& i: queries){
            int l= i[0];
            while(l <= i[1]){
                nums[l]= ((long long)nums[l] * i[3]) % mod;
                l+= i[2];
            }
        }
        int ans=0;
        for(int i: nums) ans^= i;
        return ans;
    }
};