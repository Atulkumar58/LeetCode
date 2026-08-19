/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<vector<TreeNode*>>> dp;
    void calculate(int i, int j){
        // cout<<i<<" "<<j<<endl;
        if(dp[i][j].size() > 0) return;

        if(i > j){
            dp[i][j].push_back(NULL);
            return;
        }
        // vector<TreeNode*> res; // dp[i][j]
        for(int mid= i; mid<=j; mid++){
            calculate(i, mid-1);
            calculate(mid+1, j);
            
            for(int x= 0; x<dp[i][mid-1].size(); x++){
                for(int y=0; y<dp[mid+1][j].size(); y++){
                    dp[i][j].push_back(new TreeNode(mid, dp[i][mid-1][x], dp[mid+1][j][y]));
                }
            }
        }

    }
    vector<TreeNode*> generateTrees(int n) {
        dp.resize(n+2, vector<vector<TreeNode*>>(n+1));
        calculate(1, n);
        return dp[1][n];
    }
};