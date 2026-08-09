class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        vector<vector<int>> dp= mat;
        vector<vector<pair<int, int>>> mp;
        int n=mat.size(), m= mat[0].size();
        for(int i= n-1; i>=0; i--){
            for(int j= m-1; j>=0; j--){
                if(mat[i][j]){
                    int temp= INT_MAX;
                    if(i < n-1) temp= min(temp, dp[i+1][j]);
                    else temp=0;
                    if(j < m-1) temp = min(temp, dp[i][j+1]);
                    else temp=0;
                    if(i<n-1 && j<m-1) temp= min(temp, dp[i+1][j+1]);
                    else temp=0;

                    // temp= (temp==INT_MAX)? 0: temp;

                    dp[i][j]= temp+1;
                    while(mp.size() <= temp+1) mp.push_back({});
                    mp[dp[i][j]].push_back({i, j});
                    // cout<< dp[i][j]<< " "<<i<<" "<<j<<endl;
                }
            }
        }
        int minx= INT_MAX, maxx= INT_MIN;
        int miny= INT_MAX, maxy=INT_MIN;
        for(int i= mp.size()-1; i>=0; i--){
            for(int j=0; j< mp[i].size(); j++){
                // cout<<i<<"->"<<mp[i][j].first<<" "<<mp[i][j].second<<endl;
                minx= min(minx, mp[i][j].first);
                miny= min(miny, mp[i][j].second);

                maxx= max(maxx, mp[i][j].first);
                maxy= max(maxy, mp[i][j].second);

                if(maxx - minx >= i || maxy-miny >= i) return i*i;
            }
        }
        return 0;
    }
};