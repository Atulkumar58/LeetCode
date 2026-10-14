class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
        while(sum > 0){
            if(sum >= 9){
                res+= '9';
                sum-= 9;
            }
            else{
                char ch= '0'+sum;
                res+= ch;
                sum=0;
            }
        }
        while(res.length() < num) res+='0';
        if(res.length() > num) return "";
        return res;
    }
};