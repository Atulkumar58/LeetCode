class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            switch(ch){
                case ')':
                    if(!st.empty() && st.top() =='(') st.pop();
                    else return false;
                    break;
                case '}' :
                    if(!st.empty() && st.top() =='{') st.pop();
                    else return false;
                    break;
                case ']':
                    if(!st.empty() && st.top() == '[') st.pop();
                    else return false;
                    break;
                default:
                    st.push(ch);
                    break;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};