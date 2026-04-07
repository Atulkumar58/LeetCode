class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n= positions.size();
        vector<vector<int>> h;
        for(int i=0; i<n; i++){
            int l= (directions[i] == 'R') ? 1: -1;
            h.push_back({positions[i], healths[i], l});
        }
        sort(h.begin(), h.end());

        vector<int> ans;
        stack<pair<int,int>> s;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            if(h[i][2] == 1){
                s.push({h[i][1], h[i][0]});
            }
            else{
                int t= h[i][1];
                while(!s.empty() && s.top().first < t){
                    s.pop(); t--;
                }
                if(!s.empty() && s.top().first == t){
                    s.pop(); t=0;
                }else if(!s.empty() && s.top().first > t){
                    s.top().first --;
                    if(s.top().first ==0) s.pop();
                }
                if(s.empty() && t!=0){
                    // ans.push_back(t);
                    m[h[i][0]]= t;
                }
            }
        }
        while(!s.empty()){
            m[s.top().second] = s.top().first;
            s.pop();
        }
        for(int i=0; i<n; i++){
            int t= m[positions[i]];
            if(t!=0){
                ans.push_back(t);
            }
        }
        return ans;
    }
};