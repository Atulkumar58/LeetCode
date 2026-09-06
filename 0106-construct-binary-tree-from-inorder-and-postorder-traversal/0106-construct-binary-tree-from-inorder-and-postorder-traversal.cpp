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
    vector<int> inorder;
    vector<int> postorder;
    int idx;
    TreeNode* construct(int i, int j){
        if(i > j) return NULL;
        // cout<<postorder[idx]<<" "<<idx<<endl;
        int t= postorder[idx--];

        int mid=-1;
        for(int k= i; k<=j; k++){
            if(inorder[k] == t){
                mid=k;
                break;
            }
        }

        // if(mid!= -1){
            TreeNode* res= new TreeNode(t);
            res->right= construct(mid+1, j);
            res->left= construct(i, mid-1);
        // }
        return res;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder= inorder;
        this->postorder= postorder;
        this->idx= postorder.size()-1;
        return construct(0, inorder.size()-1);
    }
};