class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        if(n>= 1e3){
            ans+= (n-1e3) +1;
        }
        return ans;
    }
};