class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;
        for(int i: fruits){
            bool possible = true;
            for(int& j: baskets){
                if(i <= j){
                    j=0;
                    possible= false;
                    break;
                }
            }
            if(possible) ans++;
        }
        return ans;
    }
};