class Solution {
public:
    string longestPrefix(string s) {
        int n= s.length();
        vector<int> kmp(n, 0);
        int i=1, j=0;
        while(i < n){
            if(s[i] == s[j]){
                kmp[i]= j+1;
                j++;
            }
            else{
                if(j==0) kmp[i]=0;
                else{
                    j= kmp[j-1];
                    continue;
                }
            }
            i++;
        }
        // for(int i: kmp){
        //     cout<<i<<" ";
        // }
        return s.substr(0,kmp[n-1]);
    }
};