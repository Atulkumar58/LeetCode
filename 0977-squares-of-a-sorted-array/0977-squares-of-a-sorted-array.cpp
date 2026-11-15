class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        vector<int> revans;
        int i=0, j=n-1;
        while(i<= j){
            if(abs(nums[i]) < abs(nums[j])){
                revans.push_back(nums[j]*nums[j]);
                j--;
            }
            else{
                revans.push_back(nums[i]*nums[i]);
                i++;
            }
        }
        reverse(revans.begin(), revans.end());
        return revans;
    }
};