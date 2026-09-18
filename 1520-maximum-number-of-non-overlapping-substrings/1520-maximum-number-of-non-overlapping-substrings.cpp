class Solution {
public:
    static bool custom (const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n= s.length();
        vector<pair<int, int>> inter(26, {-1, -1});
        for(int i=0; i<n; i++){
            char ch= s[i];
            if(inter[ch-'a'].first == -1){
                inter[ch-'a']= {i, i};
            }
            else inter[ch-'a'].second= i;
        }

        for(int i=0; i<n; i++){
            char t= s[i];
            for(int j=0; j<26; j++){
                if(t-'a' != j && inter[j].first < i && i<inter[j].second){
                    inter[j].first= min(inter[j].first, inter[t-'a'].first);
                    inter[j].second= max(inter[j].second, inter[t-'a'].second);
                    // inter[t-'a'] = inter[j];
                }
            }
        }
        vector<vector<int>> intervals;
        for(int i=0; i<26; i++){
            if(inter[i].first != -1){
                intervals.push_back({inter[i].first, inter[i].second});
            }
        }
        sort(intervals.begin(), intervals.end(), custom);
        vector<string> ans;
        int last= -1;
        for(int i=0; i<intervals.size(); i++){
            // cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(last < intervals[i][0]){
                ans.push_back(s.substr(intervals[i][0], intervals[i][1]-intervals[i][0]+1));
                last= intervals[i][1];
            }
        }
        return ans;
    }
};