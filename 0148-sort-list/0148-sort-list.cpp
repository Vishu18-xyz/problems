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
    ListNode* sortList(ListNode* head) {
        vector<int>ans;
        ListNode*  temp =head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy=new ListNode(10);
        ListNode* temp1= dummy;
        for(auto & val :ans)
        {
            temp1->next= new ListNode(val);
            temp1=temp1->next;
        }
        return dummy->next;




    }
};