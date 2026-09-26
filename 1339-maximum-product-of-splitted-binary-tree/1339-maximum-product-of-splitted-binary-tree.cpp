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
    unordered_map<TreeNode*,int>m;
    int sum(TreeNode* root){
        if(!root) return 0;
        int ans= root-> val;
        int s= sum(root->left);
        m[root->left]=s;
        ans+= s;
        s=sum(root->right);
        m[root->right]=s;
        ans+=s;
        return ans;
    }
    int maxProduct(TreeNode* root) {
        m.clear();
        long long int totalsum=sum(root);
        long long int ans=0;
        for(auto i: m){
            ans=max(ans, (totalsum-i.second)*i.second);
        }
        return ans%1000000007;
    }
};