class Solution {
public:
    int minAddToMakeValid(string s) {
        int sum=0;
        int d=0;
        int n= s.length();
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                sum++;
            }else{
                sum--;
            }
            d= max(d, sum);
        }
        int a=0;
        int temp=0;
        for(int i= n-1; i>=0; i--){
            if(s[i]=='('){
                temp++;
            }
            else {
                temp--;
            }
            a= max(a, temp);
        }
        return a+d;
    }
};