class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int depth(int node, int last){
        int ans= 0;
        for(int i: adj[node]){
            if(i== last) continue;
            ans= max(ans, depth(i, node));
        }
        return ans+1;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        adj.clear();
        for(auto& i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int edge= depth(1, 0)-1;
        long long ans=1;
        const int Mod= 1e9+7;
        for(int i=1; i<edge; i++){
            ans= (ans*2)% Mod;
        }

        return ans;
    }
};