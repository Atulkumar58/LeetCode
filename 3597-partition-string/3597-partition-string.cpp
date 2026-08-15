class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> st;
        vector<string> ans;
        string curr="";
        for(char c: s){
            curr += c;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                ans.push_back(curr);
                curr="";
            }
        }

        
        // for(auto x: st){
        //     ans.push_back(x);
        // }
        return ans;
    }
};