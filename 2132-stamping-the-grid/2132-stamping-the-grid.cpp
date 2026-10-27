class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        vector<vector<int>> tempg= grid;
        int m= grid.size();
        int n= grid[0].size();

        //down to up
        for(int j=0; j<n; j++){
            int last=0;
            for(int i=m-1; i>=0; i--){
                if(grid[i][j] == 1){
                    tempg[i][j]=0;
                    last= 0;
                }
                else{
                    last++;
                    tempg[i][j]= last;
                }
            }
        }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<tempg[i][j]<<" ";
        //     }cout<<endl;
        // }

        vector<int> stamp(n, 0);
        for(int i=0; i<m; i++){
            // for(int i: stamp) cout<<i<<" ";
            // cout<<endl;

            vector<int> temp(n, 0);
            int last=0;
            for(int j= n-1; j>=0; j--){
                if(tempg[i][j] >= stampHeight){
                    temp[j]= last+1;
                    last++;
                }
                else {
                    last=0;
                }
            }
            // for(int i: temp) cout<<i<<" ";

            int idx=-1;
            for(int j=0; j<n; j++){
                if(temp[j] >= stampWidth && idx < j){
                    for(idx=j; idx<j+temp[j]; idx++){
                        stamp[idx]= stampHeight;
                    }
                }

                if(stamp[j]==0 && grid[i][j]==0) return false;
            }

            for(int& j: stamp){
                if(j>0)j--;
            }
        }   
        return true;
    }
};