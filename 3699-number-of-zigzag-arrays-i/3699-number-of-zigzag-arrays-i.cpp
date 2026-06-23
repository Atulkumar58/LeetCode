class Solution {
public:
    const int mod= 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        vector<int> dp(r-l+1, 1);
        for(int i=1; i<n; i++){
            long long sum=0;
            if(i%2 == 1){
                for(int& j: dp){
                    int temp= j;
                    j=sum;
                    sum+= temp;
                    sum%= mod;
                }
            }
            else{
                for(int j= dp.size()-1; j>=0; j--){
                    int temp= dp[j];
                    dp[j]= sum;
                    sum+= temp;
                    sum%=mod;
                }
            }
        }

        long long sum=0;
        for(int i: dp){
            sum+= i;
            sum%= mod;
        }
        return (sum*2)%mod;
    }
};