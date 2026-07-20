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
    void getPreOrder(TreeNode* root,vector<int>& preorder){
        if(root==NULL) return;
        if(root->left) getPreOrder(root->left,preorder);
        if(root!=NULL) preorder.push_back(root->val);
        if(root->right) getPreOrder(root->right,preorder);
    }
    int kthSmallest(TreeNode* root, int k) {
         if((root->left==NULL && root->right==NULL) && k==1) return {root->val};
        vector<int> preorder;
        getPreOrder(root,preorder);
        int kSmallest,kLargest;
        int i=0;
        int n=preorder.size();
        return {preorder[k-1]};
    }
};