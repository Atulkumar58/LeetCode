class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        int n= s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                int counter=1;
                int j= i+1;
                for(; j<n; j++){
                    if(s[j]=='(') counter++;
                    if(s[j]==')') counter--;

                    if(counter==0) break;
                }
                string temp= reverseParentheses(s.substr(i+1, j-i-1));
                // cout<<temp<<" ";
                i= j;
                for(int j= temp.length()-1; j>=0; j--){
                    ans+= temp[j];
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};