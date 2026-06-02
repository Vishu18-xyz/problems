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
    int summ = 0;
    void sum(TreeNode*root, int n ){
        if(root==NULL){
            return;
        }
        n = n*10+root->val;

        if(root->left == NULL && root->right == NULL){
            summ = summ+n;
            return;
        }

        sum(root->left,n);
        sum(root->right,n);
    }
    int sumNumbers(TreeNode* root) {
        int n = 0;
        sum(root,n);
        return summ;
    }
};