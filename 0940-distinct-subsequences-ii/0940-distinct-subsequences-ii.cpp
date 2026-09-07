class Solution {
public:
    const int mod= 1e9+7;
    int distinctSubseqII(string s) {
        int n= s.length();
        vector<int> index(26, -1);
        vector<int> dp(n, 0);
        long long sum=0;
        for(int i=0; i<n; i++){
            if(index[s[i]-'a'] == -1){
                sum*=2;
                sum++;
            }
            else{
                sum+= (sum- (index[s[i]-'a'] !=0 ? dp[index[s[i]-'a'] -1] : 0));
            }

            index[s[i]-'a']= i;
            sum= (sum+mod)%mod;
            dp[i]= sum;
        }
        return dp[n-1];
    }
};