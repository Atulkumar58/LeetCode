class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m=  grid.size(), n= grid[0].size();
        vector<vector<int>> safeness(m,vector<int> (n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) {
                    safeness[i][j]=0;
                    continue;
                }
                int a= (i==0)? 100000: safeness[i-1][j];
                int b= (j==0)? 100000 : safeness[i][j-1];
                
                safeness[i][j]= min(a, b)+1;
            }
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 1) {
                    safeness[i][j]=0;
                    continue;
                }
                int a= (i==m-1)? 100000: safeness[i+1][j];
                int b= (j==n-1)? 100000: safeness[i][j+1];
                
                safeness[i][j]= min(safeness[i][j],min(a, b) +1);
            }
        }

        // for(auto i: safeness){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }cout<<endl;
        // }
        //Dijkshtra 
        //Longest path
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        priority_queue<vector<int>> pq;
        pq.push({safeness[0][0], 0, 0});
        visited[0][0]= 1;

        int x[4]= {1, 0, 0, -1};
        int y[4]= {0, 1, -1, 0};
        while(!pq.empty()){
            vector<int> v= pq.top();
            pq.pop();

            if(v[1] == n-1 && v[2]==n-1){
                return v[0];
            }

            for(int i=0; i<4; i++){
                int nx= v[1] + x[i];
                int ny= v[2]+ y[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(!visited[nx][ny]){
                        pq.push({min(safeness[nx][ny], v[0]), nx, ny});
                        visited[nx][ny]= 1;
                    }
                }
            }
        }
        return 0;
    }
};