class Solution {
public:
    static bool custom(vector<int> a, vector<int> b){
        if(a[1]-a[0] > b[1]-b[0]) return true;
        if(a[1]-a[0] == b[1]-b[0] && a[1] > b[1]) return true;
        return false;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), custom);
        int n= tasks.size();
        int ans=0;
        for(int i= n-1; i>=0; i--){
            ans+= tasks[i][0];
            if(ans < tasks[i][1]) ans= tasks[i][1];
        }
        return ans;
    }
};