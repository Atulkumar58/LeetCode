class Solution {
public:
    vector<int>dp;
    int rec(int n, bool turn){
        if(n==0){
            if(turn) return dp[0];
            else return !dp[0];
        }

        if(dp[n] != -1){
            if(turn) return dp[n];
            else return !dp[n];
        }

        for(int i=1; i*i<=n; i++){
            if(turn){
                if(rec(n-i*i, !turn)){
                    dp[n]= 1;
                    
                    return true;
                }
            }
            else {
                if(!rec(n-i*i, !turn)){
                    dp[n]= 1;
                    return false;
                }
            }
        }
        if(turn){
            dp[n]=0;
            return false;
        } 
        dp[n]= 0;
        return 1;
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1, -1);
        dp[0]=0;
        
        
        // for(int i: dp)cout<<i<<" ";
        return rec(n, 1);
    }
};