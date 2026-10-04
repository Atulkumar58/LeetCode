class Solution {
public:
    bool checkValidString(string s) {
        int n= s.length();
        stack<char> st;
        int as=0;
        for(char c: s){
            if(c=='(') st.push(c);
            if(c==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    if(as>0) as--;
                    else return false;
                }
            }
            if(c=='*') as++;
        }
        while(!st.empty()) st.pop();
        as=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]==')') st.push(s[i]);
            if(s[i]=='('){
                if(!st.empty()){
                    st.pop();
                }else{
                    if(as>0) as--;
                    else return false;
                }
            }
            if(s[i]=='*') as++;
        }
        return true;
    }
};