class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n= stones.size();
        vector<int> freq(3, 0);
        for(int i: stones){
            freq[i%3]++;
        }
        bool alice=1;
        if(freq[0] % 2 == 0){
            if(freq[1]==0 || freq[2]==0){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            int m= max(freq[1], freq[2]);
            int l= min(freq[1], freq[2]);
            if(m-l >2){
                return 1;
            }
            else if(m-l < 2){
                return 0;
            }
        }
        return 0;
    }
};