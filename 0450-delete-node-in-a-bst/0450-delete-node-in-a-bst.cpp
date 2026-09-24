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
    TreeNode* parent;
    TreeNode* find(TreeNode* root, int key){
        if(root == NULL) return NULL;

        if(root -> val == key){
            return root;
        }
        
        TreeNode* res= find(root->left, key);
        if(res==NULL) res= find(root->right, key);
        if(res){
            if(parent==NULL) parent = root;
            return res;
        }
        return NULL;
    }
    TreeNode* join (TreeNode* t1, TreeNode* t2){
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;

        TreeNode* smallest= t2;
        while(smallest->left){
            smallest= smallest->left;
        }
        smallest->left= t1;
        return t2;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        parent= NULL;
        TreeNode* node= find(root, key);
        if(!node) return root;
        TreeNode* child= join(node->left, node->right);
        if(!parent) return child;
        if(parent->left == node){
            parent->left= child;
        }
        else parent->right = child;

        return root;
    }
};