/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return nullptr;
        ListNode* slow =head;
        ListNode* fast = head;
        // ListNode* res=nullptr;
        while(fast && fast->next){
             slow= slow->next;
            fast= fast ->next->next;
             if (slow == fast) {
                ListNode* start = head;
                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }
        // int index=0;
        // ListNode* temp=head;
        // while(temp){
        //     if(temp->val==res->val)return index;
        //     temp=temp->next;
        //     index++;
        // }
        return nullptr;
    }
};