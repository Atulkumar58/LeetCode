class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> p(1001, 0), n(1001, 0);

        for(int i: nums){
            if(i > 0) p[i]=1;
            else n[(-i)]=1;
        }

        for(int i=1000; i>0; i--){
            if(p[i] && n[i]) return i;
        }
        return -1;
    }
};