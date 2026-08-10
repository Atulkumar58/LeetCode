class Solution {
public:
    vector<int>dp; //1 means person on that position of number wins
                //  0 means person on that number loses
    bool rec(int n, bool alice_turn){
        if(n==0 || dp[n] != -1){
            if(alice_turn) return dp[n];
            else return !dp[n];
        }

        for(int i=1; i*i<=n; i++){
            if(alice_turn){
                if(rec(n-i*i, !alice_turn)){
                    dp[n]= 1;
                    return true;
                }
            }
            else {
                if(!rec(n-i*i, !alice_turn)){
                    dp[n]= 1;
                    return false;
                }
            }
        }

        //person didnot find any winning stretegy that is why loses on both cases dp-> 0 
        // we return the value with respect to winning of alice which is asked in the question
        if(alice_turn){
            dp[n]=0;
            return false;
        }
        else{
            dp[n]= 0;
            return 1;
        }
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1, -1);
        dp[0]=0;
        return rec(n, 1);
    }
};