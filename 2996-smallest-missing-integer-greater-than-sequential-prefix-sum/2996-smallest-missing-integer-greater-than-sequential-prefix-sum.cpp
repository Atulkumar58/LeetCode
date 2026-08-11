class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=0;
        int n= nums.size();
        int ans=0;
        vector<bool> p(52, 0);
        bool check= 1;
        for(int i=0; i<n; i++){
            p[nums[i]]=1;
            if(check)
            if(i==0){
                sum= nums[i];
            }
            else if(nums[i] != nums[i-1]+1) check=0;
            else sum+= nums[i];
            // cout<<sum<<" ";
            ans= max(ans, sum);
        }
        while(ans <= 51 && p[ans]){
            ans++;
        }
        return ans;
    }
};