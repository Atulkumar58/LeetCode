class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        long long ans=0;
        for(int i= 9; i>=0; i--){
            int digit= n/ pow(10, i);
            digit%=10;

            if(digit){
                ans*=10;
                ans+= digit;
            }
            sum +=  digit;
        }
        return ans* sum;
    }
};