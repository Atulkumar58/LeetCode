class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> adj;
    int x;
    int dfsEdges(int i){
        if(vis[i]) return 0;
        vis[i]=1;
        x++;

        int ans= adj[i].size();
        for(int j: adj[i]){
            ans+= dfsEdges(j);
        }
        return ans;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.clear();
        adj.resize(n);
        for(auto& i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vis.resize(n, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                x=0;
                int t= dfsEdges(i);
                if(t== x*(x-1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};