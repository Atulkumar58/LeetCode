class Solution {
public:
    bool checkDivisibility(int n) {
        int num= n;
        int sum=0,mul=1;
        while(n){
            sum+=(n%10);
            mul*= (n%10);
            n/=10;
        }
        //cout<<n<<" "<<sum<<" "<<mul;
        if((num%(sum+mul)) ==0) return 1;
        return 0;
    }
};