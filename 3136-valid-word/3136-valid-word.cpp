class Solution {
public:
    string vowel= "aeiou";
    bool check(char ch){
        for(char c: vowel){
            if(c == ch || (c-'a'+'A') == ch){
                return 1;
            }
        }
        return 0;
    }
    bool checkvalid(char ch){
        if((ch < '0' || ch >'9') && (ch<'a' || ch>'z') && (ch<'A' || ch>'Z')) return 0;
        // cout<<(ch < '0') <<" "<<(ch >'9');
        return 1;
    }
    bool isValid(string word) {
        if(word.length() < 3) return 0;
        bool v=0, c=0;
        for(char ch: word){
            if(!checkvalid(ch)) return false;
            if(ch>='0' && ch<= '9') continue;

            if(check(ch)) v=1;
            else c=1;

            // cout<<ch<<" "<<v<<" "<<c<<endl;
        }
        
        if(v && c){
            return 1;
        }return 0;
    }
};