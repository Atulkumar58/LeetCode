class Solution {
public:
    static bool customcomparator(vector<int>& a, vector<int>& b){
        // return 
        if(a[1] < b[1]) return 1;
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), customcomparator);
        int n= points.size();
        long long x= LLONG_MIN;
        int ans=0;
        for(int i=0; i<n; i++){
            if(x < points[i][0]){
                x= points[i][1];
                ans++;
            }
        }
        return ans;
    }
};