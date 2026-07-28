class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> alpha(26, 0);
        for(char c:s) alpha[c-'a']++;
        string ans="";
        for(int i=0; i<26; i++){
            for(int j=0; j< alpha[i]/2; j++){
                ans+= ('a'+ i);
            }
        }
        if(s.length() % 2){
            ans+= (s[s.length()/2]);
        }
        for(int i=25; i>=0; i--){
            for(int j=0; j< alpha[i]/2; j++){
                ans+= ('a'+ i);
            }
        }
        return ans;
    }
};