class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp(2, INT_MIN);
        // int time= INT_MIN;
        for(int i=0; i<intervals.size(); i++){
            if(temp[1] < intervals[i][0]){
                //dont merge
                if(i!=0){
                    ans.push_back(temp);
                }
                temp[0]= intervals[i][0];
                temp[1]= intervals[i][1];
            }
            else{
                temp[1]= max(temp[1], intervals[i][1]);
                if(temp[0] > intervals[i][0]){
                    temp[0]= intervals[i][0];
                }
            }
        }
        ans.push_back(temp);
        return ans;
    }
};