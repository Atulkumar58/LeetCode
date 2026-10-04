class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>> v(n+1, vector<int>(m,0));
        for(int i=1; i<=n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i-1][j]=='1'){
                    v[i][j]= v[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            vector<int>l(m);
            vector<int>r(m);
            stack<pair<int,int>>s; //value , index
            s.push({-1, -1});
            for(int j=0; j<m; j++){
                while(!s.empty() && s.top().first >= v[i][j]){
                    s.pop();
                }
                l[j]= s.top().second;
                s.push({v[i][j], j});
                // cout<<l[j]<<" ";
            }
            while(!s.empty()) s.pop();
            s.push({-1, m});
            for(int j=m-1; j>=0; j--){
                while(!s.empty() && s.top().first >= v[i][j]){
                    s.pop();
                }
                r[j]=s.top().second;
                s.push({v[i][j], j});
                // cout<<r[j]<<" ";
            }
            for(int j=0; j<m; j++){
                // cout<<(r[j]-l[j]-1)*v[i][j]<<" ";
                ans= max(ans, (r[j]-l[j]-1)*v[i][j]);
            }
            // cout<<endl;
        }
        return ans;
    }
};