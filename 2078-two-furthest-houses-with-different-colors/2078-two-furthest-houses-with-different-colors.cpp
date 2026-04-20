class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi=-1;
        int n= colors.size();
        for(int i=0; i<n; i++){
            if(colors[i] != colors[n-1]){
                maxi= max(maxi, n-1-i);
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(colors[i] != colors[0]){
                maxi= max(maxi, i);
                break;
            }
        }
        return maxi;
    }
};