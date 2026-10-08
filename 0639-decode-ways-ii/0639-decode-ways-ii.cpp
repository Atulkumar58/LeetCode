class Solution {
public:
    vector<int> dp;//1 idx 2 ans
    string s;
    const int mod= 1e9+7;
    int rec(int i){
        if(i> s.length()) return 0;
        if(dp[i] != -1) return dp[i];
        if(s[i]=='0') return 0;

        long long sum=0;
        if(s[i] == '*'){
            for(int j=1; j<=9; j++){
                int temp= j;
                sum+= rec(i+1);
                
                if(i+1 < s.length()){
                    if(s[i+1] == '*'){
                        for(int k=1; k<=9; k++){
                            temp*=10;
                            temp+= k;
                                if(temp <= 26){
                                    sum+= rec(i+2);
                                }
                            temp/=10;
                        }
                    }
                    else{
                        temp*=10;
                        temp+= (s[i+1]-'0');
                        if(temp <= 26) sum+= rec(i+2);
                    }
                }
            }
        }
        else{
            int temp= (s[i]-'0');
            sum+= rec(i+1);
            if(i+1 < s.length()){
                if(s[i+1] =='*'){
                    for(int k=1; k<=9; k++){
                            temp*=10;
                            temp+= k;
                                if(temp <= 26){
                                    sum+= rec(i+2);
                                }
                            temp/=10;
                        }
                }
                else{
                    temp*=10;
                    temp+= (s[i+1]-'0');
                    if(temp <= 26) sum+= rec(i+2);
                }
            }
        }
        dp[i]= sum % mod;
        return sum%mod;
    }
    int numDecodings(string s) {
        this->s=s;
        int n= s.length();
        dp.resize(n+1,-1);
        dp[n]=1;
        return rec(0);
    }
};