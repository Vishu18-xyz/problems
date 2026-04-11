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
    void inorder(TreeNode*root,vector<int>&arr){
        if(!root){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        vector<int>arr2;

        inorder(root1,arr1);
        inorder(root2,arr2);

        int i = 0;
        int j = 0;
        int k = 0;
        int m = arr1.size();
        int n = arr2.size();
        vector<int>temp(m+n);

        while(i<m && j<n){
            if(arr1[i] < arr2[j]){
                temp[k]=arr1[i];
                k++;
                i++;
            }
            else{
                temp[k]=arr2[j];
                k++;
                j++;
            }
        }

        while(j<n){
            temp[k]=arr2[j];
            k++;
            j++;
        }

        while(i<m){
            temp[k]=arr1[i];
            k++;
            i++;
        }

        return temp;
    }
    
};