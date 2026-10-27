class Solution {
public:
int limit;
    int countways(int n, int children){
        if(n==0 && children ==0) return 1;
        if(n <0 || children <=0) return 0;

        int ans=0;
        for(int i=0; i<=limit && i<=n; i++){
            ans+= countways(n-i, children-1);
        }
        return ans;
    }
    int distributeCandies(int n, int limit) {
        this->limit= limit;
        return countways(n,  3);
    }
};