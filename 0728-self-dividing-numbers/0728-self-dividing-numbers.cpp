class Solution {
public:
    bool selfdivide(int num){
        int temp=num;
        while(temp){
            if(temp%10==0 || num % (temp%10) != 0) return false;
            temp/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        int num= left;
        vector<int> ans;
        for(int i= left; i<= right; i++){
            if(selfdivide(i)) ans.push_back(i);
        }
        return ans;
    }
};