class Solution {
public:
    string processStr(string s) {
        string ans;
        for(char c: s){
            switch(c){
                case '*': if(ans.length() > 0) ans.pop_back();
                    break;
                case '#': ans+= ans;
                    break;
                case '%':{ int i=0, j= ans.length()-1;
                        while(i<j)swap(ans[i++], ans[j--]);
                        break;
                }
                default: ans.push_back(c);
                    break;
            }
        }
        return ans;
    }
};