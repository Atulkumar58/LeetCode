class Solution {
public:
    vector<int>values;
    vector<vector<pair<int,int>>> adj;
    vector<bool>vis;
    int maxTime;
    int ans;
    void backtrack(int node, int time, int value){
        if(time > maxTime) return;
        bool changed=0;
        if(vis[node]== false){
            value+=values[node];
            vis[node]=1;
            changed=1;
        }
        if(node == 0) ans= max(ans, value);
        for(auto i: adj[node]){
            backtrack(i.first, time+i.second, value);
        }
        if(changed){
            vis[node]= 0;
        }
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        this->values= values;
        this->maxTime= maxTime;
        int n= values.size();
        adj.clear();
        adj.resize(n);
        for(auto& i: edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vis.resize(n, 0);
        ans=0;
        backtrack(0, 0, 0);
        return ans;
    }
};