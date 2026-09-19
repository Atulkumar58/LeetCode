class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hash(n, 1);
        for(auto& i: edges){
            hash[i[1]]=0;
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(hash[i]) ans.push_back(i);
        }
        return ans;
    }
};