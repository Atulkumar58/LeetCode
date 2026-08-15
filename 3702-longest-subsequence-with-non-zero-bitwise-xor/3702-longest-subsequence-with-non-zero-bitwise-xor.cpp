class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int temp=0;
        bool allz=1;
        for(int i: nums) {temp^= i;
            if(i) allz= 0;}

        if(temp) return nums.size();

        if(allz) return 0;
        return nums.size()-1;

    }
};