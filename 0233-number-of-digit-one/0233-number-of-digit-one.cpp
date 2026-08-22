class Solution {
public:
    int countDigitOne(int n) {
        int ans=0;
        long long q= 10;
        for(int i=0; i<10; i++){
            ans+= ((n/q)*(q/10));
            int digit= (n/(q/10))%10;

            if(digit == 1){
                ans+= ((n%(q/10))+1);
            }
            else if(digit > 1){
                ans+= (q/10);
            }

            if(q > n) break;
            q*=10;
        }
        return ans;
    }
};