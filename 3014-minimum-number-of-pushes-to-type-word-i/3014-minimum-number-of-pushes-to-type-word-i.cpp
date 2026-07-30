class Solution {
public:
    int minimumPushes(string word) {
        vector<int>alpha(26, 0);
        for(char c:word) alpha[c-'a']++;
        sort(alpha.begin(), alpha.end(), greater<>());
        int ans=0;
        for(int i=0; i<26; i++){
            ans+= alpha[i]*(i/8 +1);
        }
        return ans;
    }
};