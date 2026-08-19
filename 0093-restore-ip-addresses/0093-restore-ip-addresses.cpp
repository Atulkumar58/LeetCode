class Solution {
public:
    vector<string> ans;
    string s;
    void backtracking(int idx, int c, string str){
        if(c==5 && idx == s.length()){
            str.pop_back();
            ans.push_back(str);
            return;
        }
        if(c==5) return;
        if(s.length() - idx > 3*(5-c))return;

        int temp=0;
        for(int i=0; i<3 && idx+i <s.length(); i++){
            str += s[idx+i];
            temp*=10;
            temp+=(s[idx+i] -'0');
            if(temp < 256){
                backtracking(idx+i+1, c+1, str+'.');
            }
            if(s[idx]=='0') break;
        }

    }
    vector<string> restoreIpAddresses(string s) {
        this->s=s;
        int n= s.length();
        // if(n > 12) return {};

        ans.clear();
        backtracking(0, 1, "");
        return ans;
    }
};