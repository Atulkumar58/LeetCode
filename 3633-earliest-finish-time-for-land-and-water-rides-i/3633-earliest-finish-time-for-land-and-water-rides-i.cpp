class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size(), n= waterStartTime.size();
        int ans= INT_MAX;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int a= landStartTime[i];
                int b= landStartTime[i]+ landDuration[i];
                int x= waterStartTime[j];
                int y= waterStartTime[j]+ waterDuration[j];
                if(x <= b){
                    ans= min(ans, b+waterDuration[j]);
                }
                else{
                    ans= min(ans, y);
                }

                if(a <= y){
                    ans= min(ans, y+ landDuration[i]);
                }else{
                    ans= min(ans, b);
                }
            }
        }
        return ans;
    }
};