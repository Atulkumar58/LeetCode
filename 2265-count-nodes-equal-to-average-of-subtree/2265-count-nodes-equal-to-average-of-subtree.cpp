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
    int res=0;
    pair<int,int> avg(TreeNode* root){
        if(!root) return {0,0};

        int sum=root->val, count=1;
        pair<int, int>p= avg(root->left);
        sum+= p.first, count+= p.second;
        p=avg(root->right);
        sum+= p.first, count+= p.second;

        if(round(sum/count) ==root->val)res++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        res=0;
        avg(root);
        return res;
    }
};