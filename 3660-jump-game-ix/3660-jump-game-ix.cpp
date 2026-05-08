class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n= nums.size();
        vector<int> max_val(n);
        int maxi=INT_MIN;
        for(int i=0;  i<n; i++){
            maxi= max(maxi, nums[i]);
            max_val[i]= maxi;
        }
        int mini= INT_MAX;
        vector<int> min_val(n);
        for(int i= n-1; i>=0; i--){
            min_val[i]= mini;
            mini= min(mini, nums[i]);
        }

        vector<int> ans(n);
        int buffer=0;
        for(int i=n-1; i>=0; i--){
            if(min_val[i] >= max_val[i]){
                buffer= max_val[i];
            }
            ans[i]= buffer;
        }
        return ans;
    }
};