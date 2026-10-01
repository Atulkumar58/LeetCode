class Solution {
public:
    long long factorial(int n){
        long long ans=1;
        for(int i=2; i<=n; i++){
            ans*=i;
        }
        return ans;
    }
    int npr(int n, int r){
        int s= min(r, n-r);
        long long fac= factorial(s);
        int b= max(r, n-r);
        b++;
        long long ans=1;
        while(b<=n){
            ans*= b;
            while( (ans%2)==0 && (fac%2)==0){
                ans/=2;
                fac/=2;
            }
            b++;
        }
        ans/=fac;
        return ans;
    }
    int climbStairs(int n) {
        long long int ans=0;
        int n1=n;
        while(n1>=0){
            ans+= npr(n, n1);
            n1-=2;
            n-=1;
        }
        return ans;
    }
};