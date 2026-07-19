class Solution {
public:
    int dx[8]= {2, -2, 2, -2, 1, 1, -1, -1};
    int dy[8]= {1, 1, -1, -1, 2, -2, 2, -2};
    unordered_map<int, bool> m;
    vector<int>target;
    bool check(int a, int b, bool toggle){
        if(a== target[0] && b== target[1] && toggle) return 1;
        if(a<0 || a>=8 ||b<0 || b>=8) return 0;
        if(toggle){
            if(m[a*10 + b]) return false;
            m[a*10 + b] = 1;
            }
        // cout<<a<<" "<<b<<endl;
        for(int i=0; i<8; i++){
            if(check(a+dx[i], b+dy[i], !toggle)) return 1;
        }
        return 0;
    }
    bool canReach(vector<int>& start, vector<int>& target) {
        this->target= target;
        m.clear();
        return check(start[0], start[1], 1);
    }
};