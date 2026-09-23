class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    bool dfs(int src, int dest){
        if(vis[src]==1) return 0;
        vis[src]=1;
        if(src == dest) return 1;

        for(int i: adj[src]){
    
            if(dfs(i, dest)) return 1;
            
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.clear(); adj.resize(n);
        vis.resize(n);
        for(auto& i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return dfs(source, destination);
    }
};