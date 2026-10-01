class Solution {
public:
    string s1, s2, s3;
    unordered_set<int> s;
    int enc(int i, int j){
        return i*100+j;
    }
    bool check(int i, int j){
        // cout<<i<<" "<<j<<endl;
        if(i==s1.length() && j== s2.length()) return true;
        if(s.find(enc(i, j)) != s.end()){
            return false;
        }

        if(i<s1.length() && s3[i+j] == s1[i]){
            if(check(i+1, j)) return true;
        }
        if(j<s2.length() && s3[i+j] == s2[j]){
            if(check(i, j+1)) return true;
        }

        s.insert(enc(i, j));
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        this->s1= s1;
        this->s2= s2;
        this->s3= s3;
        return check(0, 0);
    }
};