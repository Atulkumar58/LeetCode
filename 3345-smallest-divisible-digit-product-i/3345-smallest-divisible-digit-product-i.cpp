class Solution {
public:
    bool check(int n, int t){
        int m=1;
        while(n!=0){
            m *= (n%10);
            n/=10;
            // cout<<m<<" ";
        }
        if(m%t==0) return 1;
        return 0;

    }
    int smallestNumber(int n, int t) {
        int num= n;
        
        while(!check(num, t)){
            num++;
            // cout<<num<<" ";
        }
        return num;
    }
};