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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long int ans=0;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int mmin=q.front().second;
            long long int first,last;
            for(int i=0;i<size;i++){
                long long int cur_idx=q.front().second-mmin;
                TreeNode* curr=q.front().first;
                q.pop();
                if(i==0) first=cur_idx;
                if(i==size-1) last=cur_idx;
                if(curr->left) q.push({curr->left,2*cur_idx+1});
                if(curr->right) q.push({curr->right,2*cur_idx+2});
            }
            ans=max(ans,last-first+1);
        }
        return (int)ans;
    }
};