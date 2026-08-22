class Solution {
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // this->matrix= matrix;
        vector<pair<int, int>> indices;
        int n= matrix.size(), m= matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) indices.push_back({i, j});
        }

        
        sort(indices.begin(), indices.end(), [&matrix](const pair<int, int>& a, const pair<int, int>& b) {
            return matrix[a.first][a.second] < matrix[b.first][b.second]; 
        });

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res= 0;
        for(auto& [i, j]: indices){
            int t=0;
            //left
            if(i>0 && matrix[i-1][j] < matrix[i][j]) t= max(t, dp[i-1][j]);
            if(j>0 && matrix[i][j-1] < matrix[i][j]) t= max(t, dp[i][j-1]);
            if(i < n-1 && matrix[i+1][j] < matrix[i][j]) t= max(t, dp[i+1][j]); 
            if(j<m-1 && matrix[i][j+1] < matrix[i][j]) t=max(t, dp[i][j+1]);

            dp[i][j]= t+1;
            res= max(res, t+1);
        }
        return res;
    }
};