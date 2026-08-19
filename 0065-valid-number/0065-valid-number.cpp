class Solution {
public:
    bool isNumber(string s) {
        bool p_m= 1; //plus minus
        bool p=1; //dot 
        bool e=1;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='+' || s[i]=='-'){
                if(!p_m) return 0;
                if((i==s.length()-1) || (s[i+1] == 'e' || s[i+1] =='E')) return 0;
                p_m = 0;
            }
            else if(s[i]=='.'){
                if(!p) return 0;
                if((i>0 && s[i-1] <='9' && s[i-1] >='0') || (i<s.length()-1 && s[i+1] <='9' && s[i+1]>='0')){
                    p=0;
                }else return 0;
            }
            else if(s[i] == 'e' || s[i]=='E'){
                if(!e) return 0;
                e=0;
                p=0;
                p_m=1;
            }
            else if(s[i] <='9' && s[i] >='0'){
                p_m = 0;
            }
            else return 0;
        }
        if(s.back() == 'e' || s[0]=='e' || s.back()=='E' || s[0]=='E') return false;
        return 1;
    }
};