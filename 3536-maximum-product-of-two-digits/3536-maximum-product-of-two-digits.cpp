class Solution {
public:
    int maxProduct(int n) {
        vector<int> dig(10, 0);
        while(n){
            dig[n%10] ++;
            n/=10;
        }

        int ans=0;
        for(int i=9; i>=0; i--){
            if(dig[i] >0 && ans > 0){
                return ans*i;
            }
            else if(dig[i]>0){
                // cout<<ans;
                ans= i;
                if(dig[i] > 1){
                    return i*i;
                }
            }
        }
        return ans;
    }   
};