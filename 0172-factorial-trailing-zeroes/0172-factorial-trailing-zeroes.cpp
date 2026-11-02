class Solution {
public:
    int trailingZeroes(int n) {
          int ans=0;
          int d=5;
          while(d<=n){
            ans+=(n/d);
            d*=5;
          }
          return ans;
    }
};