class Solution {
public:
    class custom{
        public:
            bool operator()(const vector<int>& a, vector<int>& b){
                if(a[1]==b[1]){
                    return a[0]<b[0];
                }
                return a[1] < b[1];
            }
    };
    int binarysearch(vector<vector<int>>& intervals, int j, int num){
        int i=0;
        while(i <= j){
            int mid= (i+j)/2;

            if(intervals[mid][1] < num){
                i= mid+1;
            }else{
                j= mid-1;
            }
        }
        return j;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n= intervals.size();
        for(int i=0; i<n; i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(), custom());
        // for(auto i: intervals){
        //     for(int j: i){
        //         cout<<j<<" ";
        //     }cout<<endl;
        // }cout<<endl;
        vector<vector<long long>> dp(n, {0});
        vector<vector<long long>> temp(n);
       
        for(int i=0; i<4; i++){
            long long sum=0;
            temp.clear();
            temp.resize(n);
            for(int j=0; j<n; j++){
                    int idx= binarysearch(intervals, j-1, intervals[j][0]);
                        if(sum < (idx >=0 ? dp[idx].back() : 0) + intervals[j][2]){
                            if(idx>=0) {temp[j]= dp[idx];
                            temp[j].pop_back();}
                            temp[j].push_back(intervals[j][3]);
                            sum= (idx>=0 ? dp[idx].back() : 0 )+intervals[j][2];
                        }
                        else if(sum == (idx >= 0 ? dp[idx].back() : 0) + intervals[j][2]){
                            vector<long long> x= temp[j-1];
                            vector<long long> y;
                            if(idx >= 0) y= dp[idx];
                            x.pop_back();
                            if(idx >= 0) y.pop_back();
                            y.push_back(intervals[j][3]);
                            sort(x.begin(), x.end()); sort(y.begin(), y.end());
                            int i=0;
                            bool possible = true;
                            while(i < x.size() && i<y.size()){
                                if(x[i] < y[i]){
                                    possible= 1;
                                    break;
                                }else if(x[i] > y[i]){
                                    possible= 0;
                                    break;
                                }
                                i++;
                            }
                            temp[j]= possible ? x : y;
                        }
                        else{
                            temp[j]= temp[j-1];
                            continue;
                        }
                    // cout<< "("<<j<<" "<<sum<<")";
                    temp[j].push_back(sum);
                }
            // cout<<endl;
            dp= temp;
            // for(auto i: dp){
            //     for(int j: i)cout<<j<<" ";
            //     cout<<endl;
            // }cout<<endl;
        }
        dp[n-1].pop_back();
        sort(dp[n-1].begin(), dp[n-1].end());
        return vector<int>(dp[n-1].begin(), dp[n-1].end());
    }
};