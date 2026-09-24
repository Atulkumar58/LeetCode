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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* t= new TreeNode(val);
        if(root == NULL) return t;
        TreeNode* curr= root;
        while(curr){
            if( val > curr->val){
                if(curr-> right==NULL){
                    curr->right= t;
                    break;
                }
                curr= curr-> right;
            }else if(val< curr->val ){
                if(curr->left == NULL){
                    curr->left =t;
                    break;
                }
                curr= curr->left;
            }
        }
     return root;
    }
};