class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s=INT_MAX, l = INT_MIN;
        for(int i: nums){
            s= min(s, i);
            l= max(l, i);
        }

        int t= l%s;
        while(t){
            t= l;
            l=s;
            s= t%s;
            t= l%s;
        }
        return s;
    }
};