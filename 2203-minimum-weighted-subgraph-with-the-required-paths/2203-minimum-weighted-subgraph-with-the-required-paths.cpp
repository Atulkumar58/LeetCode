class Solution {
public:
    vector<long long> minDist(vector<vector<pair<int, int>>>& graph, int node){
        int n= graph.size();
        vector<long long> ans(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.push({0, node});
        ans[node]= 0;
        while(!pq.empty()){
            pair<long long, int> p= pq.top();
            pq.pop();

            if(ans[p.second] < p.first) continue;
            ans[p.second]= p.first;

            for(auto& i: graph[p.second]){
                if(ans[i.first] >= p.first + i.second){
                    ans[i.first]= p.first+i.second;
                    pq.push({ans[i.first], i.first});
                }
            }
        }
        return  ans;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<pair<int, int>>> rev(n);
        for(auto& i: edges){
            graph[i[0]].push_back({i[1], i[2]});
            rev[i[1]].push_back({i[0], i[2]});
        }
        vector<vector<long long>> distances(3);
        distances[0]= minDist(graph, src1);
        distances[1]= minDist(graph, src2);
        distances[2]= minDist(rev, dest);
        long long ans=LLONG_MAX;
        for(int j=0; j<n; j++){
            long long sum=0;
            bool good= true;
            for(int i=0; i<3; i++){
                if(distances[i][j] == LLONG_MAX){
                    good = false;
                    break;
                }
                sum+= distances[i][j];
            }
            if(good) ans= min(ans, sum);
        }
        return ans== LLONG_MAX ? -1 : ans;
    }
};