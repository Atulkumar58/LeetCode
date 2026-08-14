class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> alpha(26,0);
        int n= s.length();
        int i=0, j=0;
        int length=0;
        while(j < n){
            if(alpha[s[j] -'a'] < 2){
                alpha[s[j++]-'a']++;
            }else{
                alpha[s[i++]-'a']--;
            }
            length= max(length, j-i);
        }
        return length;
    }
};