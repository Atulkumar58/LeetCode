class Solution {
public:
    int ultimateparent(vector<int>& parent, int node){
        // cout<<node<<" ";
        if(parent[node] == -1) return node;

        int t= ultimateparent(parent, parent[node]);
        parent[node]= t;
        return t;
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<vector<bool>> res(n, vector<bool>(n, 0));
        for(auto &v : restrictions){
            res[v[0]][v[1]]=1;
            res[v[1]][v[0]]=1;
        }

        vector<int>parent(n, -1);
        vector<bool> ans;
        for(int i=0; i<requests.size(); i++){
            // cout<<"\ncall 1 ";
            int a= ultimateparent(parent, requests[i][0]);
            // cout<<"\ncall 2 ";
            int b= ultimateparent(parent, requests[i][1]);
            if(res[a][b] == 1){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
                if(a==b) continue;
                parent[b]= a;
                for(int k=0; k<n; k++){
                    res[a][k] = res[a][k] | res[b][k];
                    res[k][a] = res[k][a] | res[k][b];
                }
            }
        }
        return ans;
    }
};