class Graph {
public:
    vector<vector<pair<int, int>>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph.clear();
        graph.resize(n);

        for(auto& i: edges){
            graph[i[0]].push_back({i[1], i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        pq.push({0, node1});
        vector<int> dist(graph.size(), INT_MAX);
        dist[node1]=0;
        while(!pq.empty()){
            pair<int, int>p= pq.top();
            pq.pop();

            if(p.second == node2) return p.first;
            
            for(auto& i: graph[p.second]){
                if(dist[i.first] > p.first+ i.second){
                    dist[i.first] = p.first+i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */