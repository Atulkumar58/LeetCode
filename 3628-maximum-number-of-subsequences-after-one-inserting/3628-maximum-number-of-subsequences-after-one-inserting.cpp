class Solution {
public:
    long long numOfSubsequences(string s) {
        long long l=0,c=0, t= 0;
        int n= s.length();
        for(char ch: s){
            // if(ch == 'L') l++;
             if(ch =='T') t++;
            // else if(ch == 'C')c++;
        }
        long long ans=0;
        long long sum= 0;
        long long temp=0;
        long long t2= 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'C'){
                ans += (long long)l*t;
                temp += l;
                t2 += t;
                c++;
            }
            else if(s[i] == 'L') l++;
            else if(s[i] == 'T') t--;
            sum = max(sum, l*t);
            // cout<<sum << " "<<ans<<endl;
        }
        sum = max(sum, temp);
        sum = max(sum, t2);
        return sum+ans;
    }
};