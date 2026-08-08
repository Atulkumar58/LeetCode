class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        vector<int>dp(n+1, 0);
        int idx= word2.size()-1;
        for(int i=n-1; i>=0; i--){
            if(idx>=0 && word1[i] == word2[idx]){
                dp[i]= dp[i+1]+1;
                idx--;
            }else{
                dp[i] = dp[i+1];
            }
        }
        // for(int i: dp) cout<<i<<" ";
        bool same= false;

        vector<int> ans;
        idx=0;
        for(int i=0; i<n && idx<word2.size(); i++){
            if(word1[i] == word2[idx]){
                ans.push_back(i);
                idx++;
            }
            else if(same==0 && ans.size() + 1+ dp[i+1] >= word2.size()){
                ans.push_back(i);
                same=1;
                idx++;
            }
        }
        if(ans.size() == word2.size()) return ans;
        return {};
    }
};