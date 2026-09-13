class Solution {
public:
    //KMP
    string longestPrefix(string s) {
        int n= s.length();
        vector<int> pre(n, 0);
        int i=0;
        for(int j=1; j<n; j++){
            while(i!=0 && s[i] != s[j]){
                i= pre[i-1];
            }
            if(s[i] == s[j]){
                i++;
                pre[j]= i;
            }
            else{
                pre[j]=i;
            }
        }
        return s.substr(0, pre[n-1]);
    }
};