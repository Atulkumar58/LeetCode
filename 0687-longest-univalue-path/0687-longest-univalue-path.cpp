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
    int ans;
    int longest(TreeNode* root){
        if(root== NULL) return 0;
        int a= longest(root->left);
        int b= longest(root->right);
        int r=0;
        if(root->left && root->left->val == root->val && root->right && root->right->val == root->val){
            ans= max(ans, a+b);
            r= max(a, b);
        }
        else if(root->left && root->left->val == root->val){
            ans= max(ans, a);
            r= a;
        }
        else if(root->right && root->right->val == root->val){
            ans= max(ans, b);
            r=b;
        }
        return r+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        ans=0;
        longest(root);
        return ans;
    }
};