class Solution {
    int mod= (int)1e9+7;
    public int xorAfterQueries(int[] nums, int[][] queries) {
        for(int i=0; i<queries.length; i++){
            int l= queries[i][0], r= queries[i][1];
            while(l <= r){
                nums[l]= (int)(((long)nums[l] * queries[i][3])%mod);
                l+= queries[i][2];
            }
        }
        int n= nums.length;
        int ans=0;
        for(int i=0; i<n; i++){
            ans^= nums[i];
        }
        return ans;
    }
}