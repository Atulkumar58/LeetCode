class Solution {
public:
    bool find(string& s, unordered_map<string, bool>& word, int idx, unordered_map<int, bool>& m){
        if(idx == s.length()) return true;
        if(m.find(idx)!= m.end()){
            return m[idx];
        }
        for(int i= 1; i<=s.length()-idx; i++){
            if(word[s.substr(idx, i)]==1) {
                if(find(s, word, idx+i, m)){
                    return true;
                }
            }
        }
        m[idx]= false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> word;
        for(auto i: wordDict){
            word[i]=1;
        }

        int n= s.length();
        unordered_map<int, bool> m;
        return find(s, word, 0, m);
    }
};