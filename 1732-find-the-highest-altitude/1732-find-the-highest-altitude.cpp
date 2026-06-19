class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int s=0;
        for(int i: gain){
            s+= i;
            ans= max(ans, s);
        }
        return ans;
    }
};