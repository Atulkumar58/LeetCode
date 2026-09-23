class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, bool>>> adj(n);
        for(auto& i: redEdges) adj[i[0]].push_back({i[1], 1});
        for(auto& i: blueEdges) adj[i[0]].push_back({i[1], 0});

        vector<pair<int, int>> minDist(n, {INT_MAX, INT_MAX});//1 blue 2 red
        queue<pair<int, bool>> q;
        q.push({0, true});
        q.push({0, false});
        q.push({-1, false});
        int dist=0;
        while(q.size() > 1){
            pair<int, bool> p= q.front();
            q.pop();
            if(p.first == -1){
                q.push({-1, 0});
                dist++;
                continue;
            }

            // cout<<p.first<<" ";
            if(p.second){
                //last was red
                if(minDist[p.first].second <= dist) continue;
                minDist[p.first].second= dist;
            }else{
                //last was blue
                if(minDist[p.first].first <= dist) continue;
                minDist[p.first].first= dist;
            }

            for(auto& i: adj[p.first]){
                if(p.second != i.second){
                    q.push({i.first, i.second});
                }
            }
            
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            int t=min(minDist[i].first, minDist[i].second);
            ans.push_back(t==INT_MAX ? -1 : t);
        }
        return ans;
    }
};