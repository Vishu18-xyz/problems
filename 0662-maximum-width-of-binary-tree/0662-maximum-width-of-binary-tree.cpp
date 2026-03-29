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
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxwidth = 0;

        while(!q.empty()){
            int size = q.size();
            int start  = q.front().second;
            int end  = q.back().second;
            maxwidth = max(maxwidth,end-start+1);

            for(int i = 0; i<size; i++){
               TreeNode*temp = q.front().first;
               int pos = q.front().second;

               if(temp->left){
                q.push({temp->left,pos*2});
               }
               if(temp->right){
                q.push({temp->right,pos*2+1});
               }
            }
        }

        return maxwidth;
    }
};