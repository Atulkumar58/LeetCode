class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& i: times){
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> minTime(n+1, INT_MAX);
        queue<int>q;
        q.push(k);
        minTime[k]= 0;
        while(!q.empty()){
            int t= q.front();
            q.pop();
            for(auto& i: adj[t]){
                if(minTime[i.first] > minTime[t]+i.second){
                    minTime[i.first]= minTime[t]+i.second;
                    q.push(i.first);
                }
            }
        }
        int ans=0;
        minTime[0]=0;
        for(int i: minTime){
            if(i==INT_MAX) return -1;
            ans= max(ans, i);
        }
        return ans;
    }
};