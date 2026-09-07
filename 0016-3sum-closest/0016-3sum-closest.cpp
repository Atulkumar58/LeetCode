class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        long long ans= INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int j=i+1, k= n-1;
            while(j < k){
                int sum= nums[i]+nums[j]+nums[k];
                if(abs(ans- target) > abs(sum-target)){
                    ans= sum;
                }

                if(sum < target){
                    j++;
                }
                else k--;
            }
        }
        return ans;
    }
};