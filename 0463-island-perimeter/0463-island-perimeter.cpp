class Solution {
public:
    vector<vector<int>> grid;
    int x[4]= {0,0,-1,1};
    int y[4]= {-1,1,0,0};
    int dfs(int i, int j){
        grid[i][j]=-1;

        int ans=0;
        for(int idx=0; idx<4; idx++){
            int xn= i+x[idx];
            int yn= j+y[idx];
            if(xn >=0 && yn>=0 && xn<grid.size() && yn<grid[0].size() && grid[xn][yn]==1){
                    ans+= dfs(xn, yn);
            }
            // else ans++;
            if(xn<0 || xn>=grid.size() || yn<0 || yn>=grid[0].size() || grid[xn][yn]==0){
                ans++;
            }
        }
        cout<<ans<<" ";
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid= grid;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};