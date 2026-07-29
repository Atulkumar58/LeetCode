class Solution {
public:
    vector<vector<int>> m;
    vector<int> coins;
    vector<vector<int>> adj;
    int k;
    int n;
    int rec_fun(int node, int count, int parent){
        count = min(count, 14);
        if(m[node][count] != -1) return m[node][count];
        int temp= coins[node] >> count;
        int a=0, b=0;
        bool poss= 1;

        for(int x: adj[node]){
            if(x==parent)continue;
            a+= rec_fun(x, count, node);
        }
        if(temp-k + a < temp/2 + (a/2)){
            for(int x: adj[node]){
                if(x==parent)continue;
                b+= rec_fun(x, count+1, node);
            }
        }
        // cout<<a<<" "<<b<<endl;
        m[node][count] =max(a+ temp-k, b+temp/2);
        return m[node][count];
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        this-> n= coins.size();
        adj.clear();
        adj.resize(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        m.resize(n, vector<int>(15, -1));
        this->coins= coins;
        this->k=k;
        return rec_fun(0,0, -1);
    }
};