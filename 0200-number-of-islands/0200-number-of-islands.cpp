class Solution {
public:
    vector<vector<char>> grid;
    void traversal(int i, int j, vector<vector<bool>>& visited){
        if(i==-1 || j==-1) return;
        if(i== visited.size() || j==visited[0].size()) return;
        if(visited[i][j]== true) return;
        if(grid[i][j]=='0') return;
        visited[i][j]=true;

        traversal(i, j+1, visited);
        traversal(i+1, j, visited);
        traversal(i-1, j, visited);
        traversal(i, j-1, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        this-> grid= grid;

        int m=grid.size();
        int n= grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans=0;
        // for(auto i: grid){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<n; j++){
                // cout<<visited[i][j]<<" "<<grid[i][j]<<endl;
                if(visited[i][j]==false && grid[i][j]=='1'){
                    ans++;
                    traversal(i, j, visited);
                }
            }
        }   
        return ans;
    }
};