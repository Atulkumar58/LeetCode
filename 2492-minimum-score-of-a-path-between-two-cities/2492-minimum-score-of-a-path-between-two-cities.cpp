class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<bool> visited(n+1, 0);
        int ans=INT_MAX;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int t= q.front();
            q.pop();
            if(visited[t]) continue;
            visited[t]=1;
            // cout<<t<<endl;
            for(auto i: adj[t]){
                // cout<<i.first<<" "<<i.second<<endl;
                ans= min(ans, i.second);
                q.push(i.first); 
            }
        }
        return ans;
    }
};