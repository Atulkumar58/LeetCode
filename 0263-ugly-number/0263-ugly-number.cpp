class Solution {
public:
    void value(int& n, int d){
        while(n % d ==0){
            n/=d;
        }
    }
    bool isUgly(int n) {
        if(n == 0) return 0;
        value(n, 2);
        value(n, 3);
        value(n, 5);

        if(n == 1){
            return true;
        }return 0;
    }
};