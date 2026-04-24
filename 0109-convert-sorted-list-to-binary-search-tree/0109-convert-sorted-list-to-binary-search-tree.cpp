/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* construct(int start , int end, vector<int> &arr){
        
        if(start > end){
            return nullptr;
        }

        int mid = (start+end)/2;
        TreeNode*root = new TreeNode(arr[mid]);
        root->left = construct(start, mid-1, arr);
        root->right = construct(mid+1,end, arr);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        ListNode*temp = head;
        
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        int start = 0;
        TreeNode*root1;
        int end = n-1;
        root1 = construct(start,end,arr);
        return root1;
    }
};