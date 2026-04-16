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
    void traversal(TreeNode*root, vector<int> &ans){
        if(!root){
            return;
        }
        traversal(root->left,ans);
        ans.push_back(root->val);
        traversal(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        traversal(root,inorder);

        int n = inorder.size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(inorder[i]+ inorder[j]==k){
                    return 1;
                }
            }
        }
        return 0;
    }
};