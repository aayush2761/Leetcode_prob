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
    ListNode* reverseList(ListNode* head) {
        vector<int>res;
        ListNode* temp=head;
        while(temp){
            res.push_back(temp->val);
            temp=temp->next;
        }
        reverse(res.begin(),res.end());
        ListNode* dummy= new ListNode(0);
        ListNode* tail= dummy;
        for(int i=0;i<res.size();i++){
            ListNode* t= new ListNode(res[i]);
            tail->next= t;
            tail = tail->next;

        }
        return dummy->next;
    }
};