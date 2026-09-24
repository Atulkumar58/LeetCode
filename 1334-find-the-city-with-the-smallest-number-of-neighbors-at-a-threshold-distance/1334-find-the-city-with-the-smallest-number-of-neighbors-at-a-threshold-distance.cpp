class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    int countNeighbour(int city, int threshold){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        vector<int> dist(graph.size(), INT_MAX);
        pq.push({0, city});
        dist[city]=0;
        while(!pq.empty()){
            pair<int, int> p= pq.top();
            pq.pop();

            for(auto& i: graph[p.second]){
                if(dist[i.first] > p.first + i.second && p.first+i.second <= threshold){
                    dist[i.first] = p.first + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }

        int ans=0;
        for(int i: dist) {
            if(i!= INT_MAX) ans++;
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        graph.clear();
        graph.resize(n);
        for(auto& i: edges){
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        int ans=INT_MAX;
        int city=-1;
        for(int i=0; i<n; i++){
            int t= countNeighbour(i, distanceThreshold);
            cout<<t<<" ";
            if(t <= ans){
                ans= t;
                city= i;
            }
        }
        return city;
    }
};