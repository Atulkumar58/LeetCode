class Solution {
public:
    int n=0;
    int ans=0;
    int k;
    int calculate(int val){
        long long temp= val;
        int res=0;
        long long hash=1;
        while(temp <= n){
            int x= n-temp+1;
            if(hash <= x){
                res+= hash;
                hash*=10;
            }
            else{
                res+= x;
                break;
            }
            temp*=10;
        }
        return res;
    }
    void backtrack(int num){
        int x= calculate(num);
        // cout<<num<<" ";
        if(k <= x){
            k--;
            // cout<<k<<endl;
            if(k==0){
                ans= num;
                return;
            }
            for(int i=0; i<10; i++){
                if(k) backtrack(num*10+i);
            }
        }
        else{
            k-=x;
            // cout<<k<<endl;
        }
    }
    int findKthNumber(int n, int k) {
        this->n= n;
        this->k= k;
        cout<<calculate(10);
        for(int i=1; i<10;i++){
            if(this->k){
                backtrack(i);
            }
        }
        return ans;
    }
};