class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0; i<=n && i<=limit; i++){
            int sum= n- i;
            int high= min(limit, sum);
            int low= max(0, sum-limit);

            if(high >= low){
                ans+= high-low+1;
            }
        }
        return ans;
    }
};