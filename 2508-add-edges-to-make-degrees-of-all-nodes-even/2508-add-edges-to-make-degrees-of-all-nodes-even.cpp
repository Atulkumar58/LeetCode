class Solution {
public:
    bool checkexist(vector<vector<int>>& adj, int a, int b){
        for(int i: adj[a]){
            if(i==b) return true;
        }
        return false;
    }
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto& i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> odds;
        for(int i=1;i<=n; i++){
            if(adj[i].size() % 2 == 1) odds.push_back(i);
        }

        if(odds.size()== 0) return 1;
        else if(odds.size() == 4){
            int a= odds[0];
            for(int j=1;j<4; j++){
                if(checkexist(adj, a, odds[j])) continue;

                int k=1,l=1;
                for(int x=1;x<4; x++){
                    if(x!= j){
                        k= l;
                        l= x;
                    }
                }
                if(checkexist(adj, odds[k],odds[l]))continue;

                return true;
            }
        }
        else if(odds.size() == 2){
            if(checkexist(adj, odds[0], odds[1]) == false) return true;
            
            vector<int> eligible(n+1, true);
            for(int i: adj[odds[0]]) eligible[i]= false;
            for(int i: adj[odds[1]]) eligible[i]= false;

            for(int i=1; i<=n; i++){
                if(eligible[i] && i!= odds[0] && i!= odds[1]) return true;
            }
        }
        return false;
    }
};