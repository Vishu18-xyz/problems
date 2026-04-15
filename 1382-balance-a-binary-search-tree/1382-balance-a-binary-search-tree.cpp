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
    TreeNode* construct(int start , int end, vector<int> &inorder){
        
        if(start > end){
            return nullptr;
        }

        int mid = (start+end)/2;
        TreeNode*root = new TreeNode(inorder[mid]);
        root->left = construct(start, mid-1, inorder);
        root->right = construct(mid+1,end, inorder);
        return root;
    }

    void inordert(TreeNode * root , vector<int> &inorder){
        if(!root){
            return;
        }
        inordert(root->left, inorder);
        inorder.push_back(root->val);
        inordert(root->right,inorder);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inordert(root,inorder);

        int n = inorder.size();
        return construct(0,n-1,inorder);

    }
};