class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, distanceThreshold+1));
        unordered_map<int, vector<int>> adj;
        for(auto& i: edges){
            if(i[2] > distanceThreshold) continue;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            distance[i[0]][i[1]] = i[2];
            distance[i[1]][i[0]] = i[2];
        }

        vector<bool> changed(n , true);
        bool change= 1;
        queue<int>q;
        for(int i=0; i<n; i++) q.push(i);

        while(!q.empty()){
            int i= q.front();
            q.pop();
            changed[i]=0;
            
                    for(int j: adj[i]){
                        for(int k=0; k<n; k++){
                            int temp = (long long)distance[i][k] + distance[i][j];
                            if(temp < distance[j][k] && temp <= distanceThreshold){
                                distance[j][k]= distance[k][j] = distance[i][k] + distance[i][j];
                                if(!changed[k])q.push(k);
                                if(!changed[j])q.push(j);
                                changed[k]= changed[j]= 1;
                            }
                        }
                    }
        }
        int sum= INT_MAX;
        int ans=0;
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++){
                // cout<<distance[i][j]<<" ";
                if(i== j)continue;
                if(distance[i][j] <= distanceThreshold){
                    c++;
                }
            }
            // cout<<endl;
            // cout<<c<<endl;
            if(sum >= c) {
                sum= c;
                ans= i;
            }
        }
        return ans;
    }
};