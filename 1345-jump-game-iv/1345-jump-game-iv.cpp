class Solution {
public:
    vector<int> min_steps;
    unordered_map<int, vector<int>> m;
    int minJumps(vector<int>& arr) {
        int n= arr.size();
        min_steps= vector<int>(n, INT_MAX);
        
       m.clear();
        for(int i=n-1; i>=0; i--){
            m[arr[i]].push_back(i);
        }
       
       vector<bool> visited(n, 0);
       int dist=0;
        queue<int> q;
        q.push(0);
        visited[0]=1;
        q.push(-1);
        while(q.size() > 1){
            int idx= q.front();
            q.pop();
            if(idx == -1){
                dist++;
                q.push(-1);
                continue;
            }
            min_steps[idx]= dist;

            if(idx+1 < n && !visited[idx+1]){
                q.push(idx+1);
                visited[idx+1]=1;
            }
            if(idx-1 >=0 && !visited[idx-1]){
                q.push(idx-1);
                visited[idx-1]= 1;
            }

            int t= arr[idx];
            for(int i: m[t]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
            m.erase(t);
        }
        return min_steps[n-1];

    }
};