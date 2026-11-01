class Solution {
public:
    int minMoves(vector<int>& nums) {
        //PURE maths, tricky do again
        int n= nums.size();
        int mini= INT_MAX;
        int sum=0;
        for(int i: nums) {mini= min(mini, i);sum+=i;}
        return sum- n*mini;
    }
};