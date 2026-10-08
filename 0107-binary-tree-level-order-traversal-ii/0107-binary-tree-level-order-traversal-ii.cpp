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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return {};
        vector<int> tem;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            TreeNode* temp= q.front();
            q.pop();

            if(!temp){
                ans.push_back(tem);
                tem.clear();
                q.push(NULL);
                continue;
            }
            tem.push_back(temp->val);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(tem);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};