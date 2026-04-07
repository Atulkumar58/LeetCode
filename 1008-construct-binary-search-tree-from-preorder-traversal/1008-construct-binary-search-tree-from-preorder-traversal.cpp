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
    void insert(TreeNode* root, int val){
        if(val >= root->val){
            if(root->right== NULL) {
                TreeNode* curr= new TreeNode(val);
                root->right= curr;
            }else{
                insert(root->right, val);
            }
        }
        else {
            if(root->left==NULL){
                TreeNode* curr= new TreeNode(val);
                root->left= curr;
            }else{
                insert(root->left, val);
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        TreeNode* root= new TreeNode(preorder[0]);
        int n= preorder.size();
        for(int i=1; i<n; i++){
            insert(root, preorder[i]);
        }
        return root;
    }
};