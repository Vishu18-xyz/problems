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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        if(root == NULL){
            return ans;
        }
        int level = 1;
        dq.push_back(root);

        while(!dq.empty()){
            vector<int> currlevel;
            int size = dq.size();

            for(int i = 0; i<size; i++){
               if(level % 2 == 0){
                TreeNode*node = dq.back();
                dq.pop_back();
                currlevel.push_back(node->val);

                if(node->right){
                    dq.push_front(node->right);
                }

                if(node->left){
                    dq.push_front(node->left);
                }
               }

               else{
                TreeNode* node = dq.front();
                    dq.pop_front();

                    currlevel.push_back(node->val);

                  if (node->left)
                     dq.push_back(node->left);
                    if (node->right)
                      dq.push_back(node->right);
                }
               }

          ans.push_back(currlevel);
            level++;
        }

        return ans;
    }
};