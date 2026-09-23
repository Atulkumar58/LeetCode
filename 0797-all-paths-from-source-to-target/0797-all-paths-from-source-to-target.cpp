class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int node){
        path.push_back(node);
        
        if(node== graph.size()-1) {
            ans.push_back(path);
        }
        for(int i: graph[node]){
            dfs(i);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph= graph;
        dfs(0);
        return ans;
    }
};