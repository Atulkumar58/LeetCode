class Solution {
public:
    string ans;
    int count=0;
    int n, k;
    void back(string& s){
        if(s.length() == n){
            count++;
            if(k== count){
                ans= s;
            }
            return;
        }

        if(s.size()==0 || s.back()!='a'){ s+='a'; back(s); s.pop_back();}
        if(s.size()==0 || s.back() != 'b'){s+='b'; back(s); s.pop_back();}
        if(s.size() == 0 || s.back() != 'c'){s+='c'; back(s); s.pop_back();}
    }
    string getHappyString(int n, int k) {
        ans="",count=0;
        this->n= n, this->k= k;
        string s;
        back(s);
        return ans;
    }
};