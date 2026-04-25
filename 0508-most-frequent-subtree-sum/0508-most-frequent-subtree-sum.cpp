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

    int traversal(TreeNode* root,unordered_map<int, int> &freq) {
        if (!root) return 0;

        int left = traversal(root->left,freq);
        int right = traversal(root->right,freq);

        int total = left + right + root->val;

        freq[total]++;

        return total;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        vector<int> result;
        if (!root) return result;

        int x = traversal(root,freq);

        int maxFreq = 0;

        for (auto &it : freq) {
            maxFreq = max(maxFreq, it.second);
        }

        for (auto &it : freq) {
            if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};