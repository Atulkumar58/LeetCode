class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, 0);
        vector<bool> upper(26, 0);
        vector<bool> possible(26, 1);
        for(char c: word){
            if(c >= 'a'){
                if(upper[c-'a']) possible[c-'a']=0;
                lower[c-'a'] =1;
            }else{
                upper[c-'A'] = 1;
            }
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(lower[i] && upper[i] && possible[i]) ans++;
        }
        return ans;
    }
};