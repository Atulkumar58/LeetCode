class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n= dungeon.size(), m= dungeon[0].size();
        for(int i=n-1; i>=0; i--){
            for(int j= m-1; j>=0; j--){
                int last= INT_MAX;
                if(i<n-1) last= min(last, dungeon[i+1][j]);
                if(j<m-1) last= min(last, dungeon[i][j+1]);
                if(last==INT_MAX) last= 1;

                int x= last- dungeon[i][j];
                dungeon[i][j]= (x > 0) ? x : 1;
            }
        }
        return dungeon[0][0];
    }
};