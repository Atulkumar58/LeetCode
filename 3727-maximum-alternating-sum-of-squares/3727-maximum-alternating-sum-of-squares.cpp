class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        long long ans=0;
        int i=0, j= n-1;
        while(i<= j){
            if(j-i >= n/2){
                if(abs(nums[i]) < abs(nums[j])){
                    ans+= (nums[j] * nums[j]);
                    j--;
                }
                else{
                    ans+= (nums[i] * nums[i]);
                    i++;
                }
                // cout<<ans<<" ";
            }
            else{
                ans -= (nums[i]*nums[i]);
                i++;
            }
            // cout<<ans<<" ";
        }
        return ans;
    }
};