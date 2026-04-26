class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<char>> grid;
    int incx[4]= {1, 0, -1, 0};
    int incy[4]= {0, 1, 0, -1};
    bool findcycle(int x, int y, int last, char c){
        if(x<0 || y<0 || x>=grid.size() || y>= grid[0].size()) return false;
        if(grid[x][y] != c) return false;
        if(vis[x][y]) return true;
        vis[x][y]=1;
        for(int i=0; i<4; i++){
            if(i == (last+2)%4) continue;
            if(findcycle(x+incx[i], y+incy[i], i, c)) return 1;
        } 
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m= grid.size(), n= grid[0].size();
        this->grid= grid;
        vis= vector<vector<bool>>(m, vector<bool>(n, false));
        // curr= vis;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    if(findcycle(i, j, 0, grid[i][j])) return 1;
                }
            }
        }
        return false;
    }
};