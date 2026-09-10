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
    
    void averagetree(TreeNode* root, int &count,int &sum,int &nodes){
        if(!root){
            return;
        }

        int rightnodes = 0;
        int leftnodes = 0;
        int leftsum = 0;
        int rightsum = 0;

        averagetree(root->left,count,leftsum,leftnodes);
        averagetree(root->right,count,rightsum,rightnodes);

        sum = leftsum+rightsum + root->val;
    
        nodes = leftnodes+rightnodes+1;

        int average = sum/nodes;

        if(average == root->val){
            count++;
        }
    }
    
    int averageOfSubtree(TreeNode* root) {
        int sum = 0;
        int nodes = 0;
        int count = 0;
        averagetree(root,count,sum,nodes);
        return count;
    }
};