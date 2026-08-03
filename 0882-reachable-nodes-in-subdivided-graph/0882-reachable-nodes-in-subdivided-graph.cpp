class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n); // 1 node 2 edge weight
        for(auto& i: edges){
            adj[i[0]].push_back({i[1], i[2]+1});
            adj[i[1]].push_back({i[0], i[2]+1});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<bool> vis(n, 0);
        vector<int> mindist(n, -1);
        int ans=0;
        vis[0]= 1;
        while(!pq.empty()){
            pair<int, int> p= pq.top();
            pq.pop();
            if(mindist[p.second] != -1) continue;
            mindist[p.second]= p.first;

            for(auto& q: adj[p.second]){
                if(mindist[q.first] == -1){
                    if(p.first+q.second <= maxMoves){
                        if(vis[q.first] == 1){
                            pq.push({p.first + q.second, q.first});
                            ans+= q.second-1;
                            continue;
                        }
                        pq.push({p.first + q.second, q.first});
                        vis[q.first] = 1;
                        ans+= q.second;
                    }
                    else{
                       ans+= (maxMoves - p.first); 
                    }
                }
                else{
                    ans+= max(0, min(maxMoves- p.first, q.second-1-(maxMoves-mindist[q.first])));
                }
                // if(p.first + q.second <= maxMoves){
                   
                //     pq.push({p.first+ q.second, q.first});
                //     ans+= q.second;
                // }
                // else{
                //     if(mindist[q.first] == -1){
                //         ans+= (maxMoves - p.first);
                //     }
                //     else{
                //         //q.second - 1 = edge dst
                //         // maxMoves- mindist[q.first] already taken
                //         ans+= min(maxMoves- p.first, q.second-1-(maxMoves-mindist[q.first]));
                //     }
                // }

            }
            // cout<<p.second<< " " <<ans<<endl;
        }
        return ans+1;
    }
};