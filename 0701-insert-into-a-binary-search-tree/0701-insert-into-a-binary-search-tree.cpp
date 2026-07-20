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
         TreeNode* node=new TreeNode(val);
         if(root==NULL) return node;
         TreeNode* originalroot=root;
        TreeNode* parent=NULL;
        while(root){
            if(root->val > val){
                parent=root;
                root=root->left;
            }
            else{
                parent=root;
                root=root->right;
            }
        }
        if(parent->val > val) parent->left=node;
        else parent->right=node;
        return originalroot;
    }
};