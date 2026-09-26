class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        for(char ch: s){
            if(!st.empty() && st.top().first == ch){
                pair<char, int> p= st.top();
                st.pop();
                if(p.second+1 != k){
                    st.push({ch, p.second+1});
                }
            }
            else{
                st.push({ch, 1});
            }
        }
        string ans;
        while(!st.empty()){
            pair<char, int> p= st.top();
            st.pop();
            while(p.second--){
                ans+= p.first;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};