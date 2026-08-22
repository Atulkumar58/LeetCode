class Solution {
public:
    string s1, s2;
    const int a1= 30*30*30, a2=30*30, a3=30;
    map<int, bool> mp;
    int enc(int i, int j, int x, int y){
        return i*a1+j*a2+x*a3+y;
    }
    bool rec(int i, int j, int x, int y){
        cout<<i<<j<<x<<y<<endl;
        if(i > j || x> y) return 0;
        if(i==j) return 1;
        if(mp.find(enc(i, j,x,y)) != mp.end()) return mp[enc(i, j, x, y)];

        vector<int> start(26,0), end(26, 0);
        int d1=0, d2=0;
        for(int idx=0; idx<j-i; idx++){
            start[s1[i+idx]-'a']++;
            if(start[s1[i+idx]-'a'] == 0) d1--;
            else if(start[s1[i+idx]-'a'] == 1) d1++;
            start[s2[x+idx]-'a']--;
            if(start[s2[x+idx]-'a'] == 0) d1--;
            else if(start[s2[x+idx]-'a'] == -1) d1++;

            if(d1 == 0){
                if(rec(i, i+idx, x, x+idx) && rec(i+idx+1, j, x+idx+1, y)){
                    mp[enc(i, j, x, y)] = 1;
                    return 1;
                }
                // return 0;
            }
            end[s1[i+idx]-'a']++;
            if(end[s1[i+idx]-'a'] == 0) d2--;
            else if(end[s1[i+idx]-'a'] == 1) d2++;
            end[s2[y-idx]-'a']--;
            if(end[s2[y-idx]-'a'] == 0) d2--;
            else if(end[s2[y-idx]-'a'] == -1) d2++;

            if(d2 ==0){
                if(rec(i, i+idx, y-idx, y) && rec(i+idx+1, j,  x, y-idx-1)) {
                    mp[enc(i, j, x, y)] = 1;
                    return 1;
                }
                // return 0;
            }
        }
        mp[enc(i, j, x, y)] = 0;
        cout<<" false"<<endl;
        return 0;
    }
    bool isScramble(string s1, string s2) {
        mp.clear();
        this->s1=s1;
        this->s2=s2;  
        vector<int> s(26,0);
        for(char c: s1) s[c-'a']++;
        for(char c: s2) s[c-'a']--;
        for(int i: s){
            if(i) return 0;
        }
        return rec(0, s1.length()-1, 0, s2.length()-1);

    }
};