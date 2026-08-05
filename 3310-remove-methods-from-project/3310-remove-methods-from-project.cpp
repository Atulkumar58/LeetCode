class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // int n= invocations.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> rev_adj(n);
        for(auto& i: invocations){
            adj[i[0]].push_back(i[1]);
            rev_adj[i[1]].push_back(i[0]);
        }

        vector<bool> vis(n, 1);
        queue<int>q;
        q.push(k);
        vis[k]= 0;
        while(!q.empty()){
            int t= q.front();
            q.pop();

            for(int i: adj[t]){
                if(vis[i]){
                    q.push(i);
                    vis[i]=0;
                }
            }
        }

        
        for(int i=0; i<n; i++){
            if(!vis[i]) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int t= q.front();
            q.pop();
            for(int i: rev_adj[t]){
                if(vis[i]){
                    //return all
                    for(int j=0; j<n; j++) ans.push_back(j);
                    return ans;
                }
            }
        }
       
        for(int i=0; i<n; i++){
            if(vis[i]) ans.push_back(i);
        }
        
        return ans;
    }
};