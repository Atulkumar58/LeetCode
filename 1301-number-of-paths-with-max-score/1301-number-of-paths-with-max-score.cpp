class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int mod=  1e9+7;
        int m=board.size(), n=board[0].size();
        vector<vector<pair<int,int>>>dp(m,vector<pair<int, int>>(n, {0,0}));
        dp[m-1][n-1]= {0, 1};
        // 
        for(int i= m-1; i>=0; i--){
            for(int j= n-1; j>=0; j--){
                if(board[i][j] =='X' || board[i][j] == 'S' || board[i][j] == 'E') continue;

                int maxi= 0;
                int count = 0;
                if(i< m-1){
                    if(dp[i+1][j].first > maxi){
                        maxi=dp[i+1][j].first;
                        count= dp[i+1][j].second;
                    }
                    else if(dp[i+1][j].first == maxi){
                        count+= dp[i+1][j].second;
                        count%= mod;
                    }
                }
                // maxi= max(maxi, board[i+1][j]);
                if(j< n-1){
                    if(dp[i][j+1].first > maxi){
                        maxi= dp[i][j+1].first;
                        count= dp[i][j+1].second;
                    }else if(dp[i][j+1].first == maxi){
                        count+= dp[i][j+1].second;
                        count%= mod;
                    }
                }
                // maxi= max(maxi, board[i][j+1]);
                if(i< m-1 && j< n-1){
                    if(dp[i+1][j+1].first > maxi){
                        maxi= dp[i+1][j+1].first;
                        count = dp[i+1][j+1].second;
                    }
                    else if(dp[i+1][j+1].first == maxi){
                        count+= dp[i+1][j+1].second;
                        count%= mod;
                    }
                }
                // maxi= max(maxi, board[i+1][j+1]);
                dp[i][j] = {maxi+(board[i][j]-'0'), count};
                // cout<<i<<" "<<j<<" "<<dp[i][j].first<<" " <<dp[i][j].second<<endl;
            }
        }
                int i=0, j=0;
                int maxi= 0;
                int count = 0;
                if(i< m-1){
                    if(dp[i+1][j].first > maxi){
                        maxi=dp[i+1][j].first;
                        count= dp[i+1][j].second;
                    }
                    else if(dp[i+1][j].first == maxi){
                        count+= dp[i+1][j].second;
                        count%= mod;
                    }
                }
                // maxi= max(maxi, board[i+1][j]);
                if(j< n-1){
                    if(dp[i][j+1].first > maxi){
                        maxi= dp[i][j+1].first;
                        count= dp[i][j+1].second;
                    }else if(dp[i][j+1].first == maxi){
                        count+= dp[i][j+1].second;
                        count%= mod;
                    }
                }
                // maxi= max(maxi, board[i][j+1]);
                if(i< m-1 && j< n-1){
                    if(dp[i+1][j+1].first > maxi){
                        maxi= dp[i+1][j+1].first;
                        count = dp[i+1][j+1].second;
                    }
                    else if(dp[i+1][j+1].first == maxi){
                        count+= dp[i+1][j+1].second;
                        count%= mod;
                    }
                }

            if(count == 0) return {0, 0};
        return {maxi, count};
    }
};