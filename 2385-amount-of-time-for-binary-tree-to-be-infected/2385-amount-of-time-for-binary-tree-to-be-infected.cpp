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
    int minTimeforBurning(TreeNode* target,map<TreeNode*,TreeNode*>& parents){
            queue<TreeNode*> q;
            map<TreeNode*,bool> vis;
            q.push(target);
            vis[target]=true;
            int maxi=0;
            while(!q.empty()){
            int size=q.size();
            int fl=0;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    fl=1;
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    fl=1;
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parents[curr] && !vis[parents[curr]]){
                    fl=1;
                    q.push(parents[curr]);
                    vis[parents[curr]]=true;
                }
            }
                if(fl) maxi++;
            }
            return maxi;
        }
        
        TreeNode* markParents(TreeNode* root,int start,map<TreeNode*,TreeNode*>& parents){
            queue<TreeNode*> q;
            q.push(root);
            TreeNode* res;
            while(!q.empty()){
                TreeNode* curr=q.front();
                if(curr->val==start) res=curr;
                q.pop();
                if(curr->left){
                    parents[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parents[curr->right]=curr;
                    q.push(curr->right);
                }
            }
            return res;
        }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> parents;
            TreeNode* target=markParents(root,start,parents);
            int timer=minTimeforBurning(target,parents);
            return timer;
    }
};