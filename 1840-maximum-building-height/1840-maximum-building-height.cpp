class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1, 0});
        sort(res.begin(), res.end());
        for(int i=1; i<res.size(); i++){
            // if(restrictions[i][1] > restrictions[i][1]){
                if(res[i][1]-res[i-1][1] > res[i][0]-res[i-1][0]){
                    res[i][1] = res[i-1][1]+ res[i][0]-res[i-1][0];
                }
        }
        int tallest=0;
        for(int i= res.size()-2; i>=0; i--){
            if(res[i][1]-res[i+1][1] > res[i+1][0]-res[i][0]){
                res[i][1]= res[i+1][1] + res[i+1][0]-res[i][0];
            }

            int di= res[i+1][0]-res[i][0];
            int dh= abs(res[i+1][1] - res[i][1]);
            di-= dh;
            int h= max(res[i][1], res[i+1][1])+ di/2;
            tallest= max(tallest, h);
        }
        tallest= max(tallest, res.back()[1] + n- res.back()[0]);
        return tallest;
    }
};