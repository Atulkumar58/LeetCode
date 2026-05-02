class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1; i<=n; i++){
            int t= i;
            bool flag = 0;
            while(t){
                int a= t%10;
                if(a==5 || a==9 || a== 6 || a==2){
                    flag=1;
                }
                else if(!(a==0 || a==1 || a==8)) break;
                t/=10;
            }
            if(t== 0 && flag){
                ans++;
            }
        }
        return ans;
    }
};