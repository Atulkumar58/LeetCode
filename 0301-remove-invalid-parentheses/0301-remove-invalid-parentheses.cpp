class Solution {
public:
    int open;
    unordered_set<string> st;
    string s;
    void backtrack(string& temp, int idx, int o, int c){
        if(o > open) return ;
        if(o < c) return;
        if(idx == s.length()){
            //base 
            if(o== open && o==c){
                st.insert(temp);
            }
            return;
        }
        // cout<<idx<<" ";
        if(s[idx] == '('){
            temp.push_back(s[idx]);
            backtrack(temp, idx+1, o+1, c);
            temp.pop_back();
        }else if(s[idx]==')') {
            temp.push_back(s[idx]);
            backtrack(temp, idx+1, o, c+1);
            temp.pop_back();
        }
        else{
            temp.push_back(s[idx]);
            backtrack(temp, idx+1, o, c);
            temp.pop_back();
        }
        if(s[idx]=='(' || s[idx]==')') backtrack(temp, idx+1, o, c);
    }
    vector<string> removeInvalidParentheses(string s) {
        this->s=s;
        int total_open=0, total_close=0;
        int rej_open=0, rej_close=0;
        int counter=0;
        for(char ch: s){
            if(ch=='(') {
                counter++; total_open++;
            }else if(ch==')') {
                counter--; total_close++;
            }

            if(counter<0){
                rej_close++;
                counter=0;
            }
        }
        rej_open= counter;
        open= total_open- rej_open;

        string temp;
        backtrack(temp, 0, 0, 0);
        return vector<string>(st.begin(), st.end());
    }
};