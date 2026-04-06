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
    void bst(TreeNode*root, vector<int>&in){
        if(!root){
            return;
        }
        bst(root->right,in);
        in.push_back(root->val);
        bst(root->left, in);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> in;
        bst(root,in);
        int ans = INT_MAX;
        for(int i = 1 ; i<in.size(); i++){
            if(abs(in[i-1] - in[i]) < ans){
                ans = abs(in[i-1]-in[i]);
            }
        }
        return ans;
    }
};