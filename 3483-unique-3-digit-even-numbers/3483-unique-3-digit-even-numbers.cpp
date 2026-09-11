class Solution {
public:
    vector<int> digit;
    int traversal(int num, int d){
        if(d==4)
            if(num%2==0) return 1;
            else return 0;
        
        int res=0;
        for(int i=0; i<10; i++){
            if(i==0 && d==1) continue;
            if(digit[i] > 0){
                digit[i]--;
                res+= traversal(num*10+i, d+1);
                digit[i]++;
            }
        }
        return res;
    }
    int totalNumbers(vector<int>& digits) {
        digit.resize(10, 0);
        for(int i: digits) digit[i]++;
        return traversal(0, 1);
    }
};