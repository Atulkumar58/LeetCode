class Solution {
public:
    int findnum(int i, int j){
        return 10*i+j;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        unordered_map<int, int> time;

        queue<int> q;
        int n= grid.size(), m= grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] ==1 || grid[i][j]==2){
                    int temp=findnum(i, j);
                    // connnect up
                    if(i!=0 && grid[i-1][j]!=0){
                        adj[temp].push_back(temp-10);
                        adj[temp-10].push_back(temp);
                    }
                    //connect side
                    if(j!=0 && grid[i][j-1]!=0){
                        
                        adj[temp].push_back(temp-1);
                        adj[temp-1].push_back(temp);
                    }

                    if(grid[i][j]==1){
                        visited[temp]=false;
                    }else if(grid[i][j]==2){
                        visited[temp]= true;
                        q.push(temp);
                        time[temp]= 0;
                    }
                }
            }

        }
        //unordered_map<int, list<int>> adj;
        // unordered_map<int, bool> visited;
        // unordered_map<int, int> time;

        //now start dikshtra
        int ans=0;
        while(q.size()>0){
            int temp= q.front();
            
            q.pop();
            for(auto i: adj[temp]){
                if(visited[i]== false){
                    visited[i]= true;
                    q.push(i);
                    time[i]= time[temp]+1;
                    ans= max(ans, time[i]);
                    
                }
            }
        }
        for(auto i: visited){
            if(i.second== false) return -1;
        }
        return ans;

    }
};