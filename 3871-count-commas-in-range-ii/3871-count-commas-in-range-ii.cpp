class Solution {
public:
    long long countCommas(long long n) {
        long long mask=1e3;
        long long ans=0;
        while(mask <= n){
            long long t= n/mask;
            if(t==0) break;

            ans+= mask*(t-1);
            ans+= (n%mask+1);

            mask*=1000;
        }
        return ans;
    }
};