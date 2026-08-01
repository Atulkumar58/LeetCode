class Solution {
public:
    vector<int> dp;
    vector<int> nums;
    int enc(int i, int j, int turn){
        return (i*20 + j)*10+ turn;
    }
    int recursion(int i, int j, int turn){
        int temp= enc(i, j, turn);
        if(j < i) return 0;
        if(dp[temp] != INT_MIN) return dp[temp];
        
        if(turn){
            dp[temp]= min(recursion(i+1, j, !turn)- nums[i], recursion(i, j-1, !turn)- nums[j]);
        }else{
            dp[temp]= max(recursion(i+1, j, !turn)+ nums[i], recursion(i, j-1, !turn) + nums[j]);
        }
        return dp[temp];
    }
    bool predictTheWinner(vector<int>& nums) {
        dp.resize(4200, INT_MIN);
        this->nums= nums;
        if(recursion(0, nums.size()-1, 0) >= 0) return 1;
        return 0;
    }
};