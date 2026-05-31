class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m= mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i: asteroids){
            if(m >= i){
                m+= i;
            }
            else return 0;
        }
        return 1;
    }
};