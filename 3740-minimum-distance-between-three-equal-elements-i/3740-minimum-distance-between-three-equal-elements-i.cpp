class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        //sliding window
        int n= nums.size();
        int i=0, j=0;
        int ans=INT_MAX;
        vector<int> freq(n+1, 0);
        int maxf=0;
        while(j <= n && i<n){
            if(maxf >= 3){
                ans= min(ans, j-i-1);
                if(freq[nums[i]] == 3) maxf--;
                freq[nums[i]]--;
                i++;
            }
            else{
                if(j== n) break;
                freq[nums[j]]++;
                maxf= max(maxf, freq[nums[j]]);
                j++;
            }
        }
        return ans==INT_MAX ? -1 : 2*ans;
    }
};