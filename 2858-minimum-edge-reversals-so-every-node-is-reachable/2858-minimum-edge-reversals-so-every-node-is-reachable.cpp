class Solution {
public:
    vector<bool> vis;
    vector<vector<pair<int, int>>> graph;
    int edgerev(int node){
        int ans=0;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int t= q.front();
            q.pop();
            vis[t]=1;

            for(auto& i: graph[t]){
                if(!vis[i.first]){
                    if(i.second==-1) ans++;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph.resize(n); // node direction 
        for(auto& i: edges){
            graph[i[0]].push_back({i[1], 1});
            graph[i[1]].push_back({i[0], -1});
        }

        vector<int> minRev(n, -1);
        vis.resize(n, 0);
        minRev[0]= edgerev(0);
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int t= q.front();
            q.pop();

            for(auto& i: graph[t]){
                if(minRev[i.first] == -1){
                    if(i.second == 1){
                        minRev[i.first]= minRev[t]+ 1;
                    }
                    else minRev[i.first]= minRev[t]-1;

                    q.push(i.first);
                }
            }
        }
        return minRev;
    }
};