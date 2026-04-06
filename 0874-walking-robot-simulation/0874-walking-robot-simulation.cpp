class Solution {
public:
struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 31 + v.second; // Simple hash, consider better for many collisions
    }
};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pair_hash> s;
        for(auto i: obstacles){
            s.insert({i[0], i[1]});
        }
        int x[4]={0, 1, 0, -1};
        int y[4]={1, 0, -1, 0};
        int idx=0;
        int a=0, b=0;
        int n= commands.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(commands[i] < 0){
                if(commands[i] == -2){
                    idx= (idx+3)%4;
                }else{
                    idx= (idx+1)%4;
                }
            }
            else{
                int k= commands[i];
                while(k-- && s.find({a+x[idx], b+y[idx]}) == s.end()){
                    a= a+x[idx];
                    b= b+y[idx];
                }
                ans= max(ans, a*a + b*b);
            }
        }
        return ans;
    }
};