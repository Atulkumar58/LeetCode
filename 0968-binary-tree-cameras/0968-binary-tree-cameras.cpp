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
    int ans = 0;
    
    int calculate(TreeNode* root){
        int a= 2;
        int t=12;
        bool nece= false;
        if(root->left){
            t= calculate(root->left);
            a= min(a, t);
            if(t == 1){
                nece= 1;
            }
        }
        if(root->right){
            t= calculate(root->right);
            a= min(a, t);
            if(t == 1){
                nece = 1;
            }
        }
        if(!root->left && !root->right){
            a=0;
        }
        if(nece){
            ans ++;
            return -1;
        }
        return a+1;
    }
    int minCameraCover(TreeNode* root) {
        ans=0;
        if(calculate(root) == 1) ans++;
        return ans;
    }
};