class Solution {
public:
    int finishtime(vector<int>&start, vector<int>& duration, int time){
        int end_time=INT_MAX;
        for(int i=0; i<start.size(); i++){
            if(time < start[i]){
                end_time= min(end_time, start[i]+duration[i]);
            }
            else{
                end_time= min(end_time, time+duration[i]);
            }
        }
        return end_time;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m= landStartTime.size(), n= waterDuration.size();

        int min_land=INT_MAX;
        for(int i=0;i <m; i++){
            min_land= min(min_land, landStartTime[i]+landDuration[i]);
        }

        int ans= finishtime(waterStartTime, waterDuration, min_land);

        int min_water=INT_MAX;
        for(int i=0; i<n; i++){
            min_water= min(min_water, waterStartTime[i] + waterDuration[i]);
        }
        ans= min(ans, finishtime(landStartTime, landDuration, min_water));
        return ans;
    }
};