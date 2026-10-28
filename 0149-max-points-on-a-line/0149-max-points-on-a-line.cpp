class Solution {
public:
    bool check(int a, int b, int c, int x, int y){
        if(y*a == b*x+c) return true;
        return false;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n= points.size();
        // unordered_map<vector<int>, bool> dp;
        int ans=1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int a= points[j][0]-points[i][0];
                int b= points[j][1]-points[i][1];
                int c= points[j][1]*(a)- points[j][0]*b;
                // cout<<a<<" "<<b<<" "<<c<<endl;
                // if(dp.find({a, b, c}) != dp.end()) continue;
                // dp[{a, b, c}]= 1;
                int sum=0;
                for(int k=0; k<n; k++){
                    if(check(a,b,c,points[k][0], points[k][1])) sum++;
                }
                ans= max(ans,  sum);
            }
        }
        return ans;
    }
};