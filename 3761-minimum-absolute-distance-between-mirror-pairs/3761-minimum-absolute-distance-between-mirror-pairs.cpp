class Solution {
public:
    int reverse(int n){
        int rv=0;
        while(n){
            rv= rv*10+n%10;
            n/=10;
        }
        return rv;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int, int> mp;
        int length=INT_MAX;
        for(int i=0; i<n; i++){
            
            // cout<<r<<endl;
            if(mp.find(nums[i]) != mp.end()) {
                length= min(length, i- mp[nums[i]]);
                // cout<<i<<" "<<mp[r]<<endl;
            }
            int r= reverse(nums[i]);
            // while(nums[i]%10==0){
            //     nums[i]/=10;
            // }
            mp[r]= i;
        }
        return length==INT_MAX ? -1: length;
    }
};