class Solution {
public:
    int n;
    vector<string> ans;
    void backtrack(string s, int left){
        if(left == n){
            while(s.length() < 2*n){
                s+=')';
            }
            ans.push_back(s);
            return;
        }

        backtrack(s+'(', left+1);
        if(s.length() < 2*left) backtrack(s+')', left);
    }
    vector<string> generateParenthesis(int n) {
        this->n= n;
        ans.clear();
        backtrack("", 0);
        return ans;
    }   
};