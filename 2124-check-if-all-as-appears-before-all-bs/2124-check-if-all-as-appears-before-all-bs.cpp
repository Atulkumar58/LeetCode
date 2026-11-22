class Solution {
public:
    bool checkString(string s) {
        bool b=false;
        for(char ch: s){
            // cout<<ch<<" ";
            if(ch=='a' && b) return false;
            else if(ch=='b') b= true;
        }
        return true;
    }
};