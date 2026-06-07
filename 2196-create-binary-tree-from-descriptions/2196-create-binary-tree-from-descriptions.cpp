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
    // void dfs(TreeNode* head){
    //     if(!head) return;
    //     cout<<head->val<<" ";
    //     dfs(head->left);
    //     dfs(head->right);
    // }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> address;
        unordered_map<int, bool> top;
        for(auto& i: descriptions){
            TreeNode* a;
            if(address.find(i[0]) != address.end()){
                a= address[i[0]];
            }else{
                a= new TreeNode(i[0]);
                address[i[0]]= a;
                
            }
            if(top[i[0]] != 1){ top[i[0]] = 0;}
            TreeNode* b;
            if(address.find(i[1]) != address.end()){
                b= address[i[1]];
            }else{
                b= new TreeNode(i[1]);
                address[i[1]]= b;
            }

            // for(auto i: address){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }

            top[i[1]]=1;

            if(i[2] ==1){
                a->left= b;
            }else{
                a->right= b;
            }
        }

        TreeNode* head;
        // dfs(head);
        for(auto i: top){
            // cout<<i.first<<" "<<i.second<<endl;
            if(!i.second){
                return address[i.first];
            }
        }
        return NULL;
    }
};