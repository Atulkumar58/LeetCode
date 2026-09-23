class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n= friends.size();
        queue<int> q;
        vector<bool> vis(n, 0);
        q.push(id);
        vis[id]=1;
        q.push(-1);
        
        int l=0;
        while(l < level){
            if(q.empty()) break;
            int t= q.front();
            q.pop();
            if(t==-1){
                q.push(-1);
                l++;
                continue;
            }

            for(int i: friends[t]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                } 
            }
        }

        unordered_map<string, int>mp;
        while(q.size() > 1){
            int t=q.front();
            q.pop();

            for(string& s: watchedVideos[t]){
                mp[s]++;
            }
        }

        vector<pair<int, string>> v;
        for(auto it: mp){
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end());
        vector<string> ans;
        for(auto& it: v){
            ans.push_back(it.second);
        }
        return ans;
    }
};