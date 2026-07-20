class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size(), n= grid[0].size();
        k %= (m*n);
        queue<int> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // if(q.size() < k){
                    q.push(grid[i][j]);
                // }
                if(q.size() > k){
                    q.pop();
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                q.push(grid[i][j]);
                grid[i][j]= q.front();
                q.pop();
            }
        }
        return grid;
    }
};