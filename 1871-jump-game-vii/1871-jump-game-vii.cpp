class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n= s.length();
        vector<vector<int>> intervals;
        intervals.push_back({0, 0});
        vector<bool> jump(n, 0);
        int i=0;
        for(int j=0; j<n; j++){
            if(s[j] =='0'){
                while(i<intervals.size() && j > intervals[i][1]){
                    i++;
                }

                if(i<intervals.size() && intervals [i][0] <= j){
                    jump[j]=1;

                    int x= j+minJump;
                    int y= j+maxJump;
                    if(intervals.back()[1] < x-1){
                        intervals.push_back({x, y});
                    }else{
                        intervals.back()[1] = y;
                    }
                }
            }
        }
        return jump[n-1];
    }
};