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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev = head;
        ListNode*curr = head->next;

        int first = -1;
        int last = -1;

        int mindist = INT_MAX;
        int maxdist = -1;

        int count = 1;

        while(curr->next != NULL){
            ListNode * next = curr->next;

            if((curr->val > prev->val && curr->val > next->val) ||(curr->val < prev->val && curr->val < next->val)){
                if(first == -1){
                    first = count;
                }
                else{
                    mindist = min(mindist, count-last);
                }

                maxdist = max(maxdist, count-first);
                last = count;
            }

            prev = curr;
            curr = next;
            count++;
        }

        if (first == last) {
            return {-1, -1};
        }
        
        return {mindist, maxdist};
    }
};