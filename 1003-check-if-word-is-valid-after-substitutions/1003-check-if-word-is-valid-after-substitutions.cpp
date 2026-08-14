class Solution {
public:
    bool isValid(string s) {
        
        vector<char> st;
        bool possible = 1;
        for(char ch: s){
            st.push_back(ch);
            if(ch=='c' && st.size()>=3){
                int l= st.size();
                if(st[l-2]=='b' && st[l-3]=='a'){
                    for(int i=0; i<3; i++) st.pop_back();
                }
            }
        }
        if(st.size()==0) return 1;
        else return 0;
    }
};