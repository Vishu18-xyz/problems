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
    void bst(TreeNode*root,int &prev, int &ans){
        if(!root){
            return;
        }
        bst(root->left, prev,ans);
        if(prev != INT_MIN){
           ans  = min(ans,abs(prev-root->val));
        }
        prev = root->val;
        bst(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = INT_MIN;
        bst(root,prev,ans);
        return ans;
    }
};