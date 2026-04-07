class Solution {
public:
    int divide(long long dividend, long long divisor) {
        bool sign =1;
        if(dividend < 0) sign = !sign;
        if(divisor < 0) sign = !sign;

        dividend= abs(dividend);
        divisor = abs(divisor);

        long long q=0;
        long long ans=0;
        int k=31;
        while(k >= 0){
            q<<=1;
            q+= (dividend & (1 << k)) ? 1 : 0;

            ans<<=1;
            if(q >= divisor){
                ans++;
                q -= divisor;
            }
            // cout<<ans<<" ";
            k--;
        }
        ans=  (sign) ? ans : -ans;
        return ans > INT_MAX ? INT_MAX : ans;
    }
};