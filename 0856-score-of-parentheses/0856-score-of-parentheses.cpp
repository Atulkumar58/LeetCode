class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char ch: s){
            if(ch == '(') st.push(0);
            else{
                int t= st.top();
                st.pop();
                int x=st.top();
                st.pop();
                if(t==0) x++;
                else x+= (t*2);
                st.push(x);
            }

            // cout<<st.top();
        }
        // cout<<endl;
        // while(!st.empty()) {
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }
        return st.top();
    }
};