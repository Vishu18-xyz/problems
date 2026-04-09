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
    TreeNode* construct(vector<int> &preorder, int &index, int upper, int lower){

        if(index == preorder.size() || lower>preorder[index] || upper<preorder[index]){
            return NULL;
        }

        TreeNode*root = new TreeNode(preorder[index]);
        index++;
        root->left = construct(preorder,index,root->val,lower);
        root->right = construct(preorder, index, upper, root->val);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int upper = INT_MAX;
        int lower = INT_MIN;
        int index = 0;
        return construct(preorder,index,upper,lower);
    }
};