class Solution {
public:
    bool check(string s, string g, int j){
        int i=0;
        int n= s.length();
        while(i< n){
            if(s[i]!= g[j]) return false;
            i++, j++;
            j= j%n;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int n= s.length();
        for(int i=0; i<n; i++){
            if(check(s, goal, i)) return true;
        }
        return false;
    }
};