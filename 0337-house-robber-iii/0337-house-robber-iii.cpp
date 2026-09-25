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
    map<TreeNode*, vector<int>> dp;

    int maxrob(TreeNode*root, int rob){
        if(!root){
            return 0;
        }

        if(dp[root][rob] != -1){
            return dp[root][rob];
        }

        if(rob){
            return dp[root][rob] =  max(root->val + maxrob(root->left,0) + maxrob(root->right,0),maxrob(root->right,1)+maxrob(root->left,1));
        }
        else{
            return dp[root][rob] = maxrob(root->left, 1) + maxrob(root->right, 1);
        }

    }
    int rob(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            dp[node] = {-1, -1};

            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }
        }
        return maxrob(root,1);
    }
};