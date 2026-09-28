class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')') st.pop();
            int t=st.size();
            ans=max(ans, t);
        }

        return ans;
    }
};