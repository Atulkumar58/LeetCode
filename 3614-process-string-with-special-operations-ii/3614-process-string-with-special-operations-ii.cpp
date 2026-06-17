class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> length;
        long long len=0;
        for(char c: s){
            switch(c){
                case '*' : if(len)len--; break;
                case '#' : len*=2;   break;
                case '%' : break;
                default: len++; break;
            }
            length.push_back(len);
            // cout<<len<<" ";
        }
        if(length.back()-1 < k){
            return '.';
        }
        int n= s.length();
        for(int i= n-1; i>=0; i--){
            switch(s[i]){
                case '*': break;
                case '#': if(k >= length[i]/2){
                    k-= length[i]/2;
                } break;
                case '%': k= length[i]-k-1; break;
                default : if(k+1 == length[i]){
                    return s[i];
                } break;
            }
        }
        return '.';
    }
};