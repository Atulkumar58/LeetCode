class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(), n= grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        vector<vector<bool>> visited(m, vector<bool>(n , 0));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        int x[]= {1, -1, 0, 0};
        int y[]= {0, 0, 1, -1};
        while(!pq.empty()){
            vector<int> temp= pq.top();
            pq.pop();

            if(temp[1] == m-1 && temp[2] == n-1){
                if(temp[0] < health) return 1;
                return 0;
            }

            for(int i=0; i<4; i++){
                int nx= temp[1]+x[i];
                int ny= temp[2]+ y[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(!visited[nx][ny]){
                        if(grid[nx][ny] == 0 )pq.push({temp[0], nx, ny});
                        else pq.push({temp[0]+1, nx, ny});
                        visited[nx][ny]=1;
                    }
                }
            }
        }
        return 0;
    }
};