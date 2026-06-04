class Solution {
public:
    vector<int> digits;
    int wavy(int n){
        digits.clear();
        while(n){
            digits.push_back(n%10);
            n/=10;
        }

        int ans=0;
        for(int i=1; i<digits.size()-1; i++){
            if(digits[i] > digits[i+1] && digits[i-1] < digits[i]){
                ans++;
            }else if(digits[i] < digits[i+1] && digits[i-1] > digits[i]){
                ans++;
            }
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        while(num1 <= num2){
            ans+= wavy(num1);
            num1++;
        }
        return ans;
    }
};