class Solution {
public:
    bool sumGame(string num) {
        int n= num.length();
        int c=0;
        int sum=0;
        // bool poss=0;
        for(int i=0; i<n; i++){
            if(i< n/2){
                if(num[i]== '?'){
                    c++; 
                }
                else{
                    sum+= num[i]-'0';
                }
            }else{
                if(num[i] == '?') {c--; }
                else sum-= num[i]-'0';
            }
        }
        // cout<<sum <<" "<< c;
        if(sum ==0 && c==0) return false;
        if(sum >0 && c<0){
            // c= c/2;
            c= abs(c);
            if(sum%9 ==0 && c%2==0 && sum/9 == c/2){
                return false;
            }
        }
        else if(sum <0 && c>0){
            sum= abs(sum);
            if(sum%9 ==0 && c%2==0 && sum/9 == c/2){
                return false;
            }
        }
        return 1;
    }
};