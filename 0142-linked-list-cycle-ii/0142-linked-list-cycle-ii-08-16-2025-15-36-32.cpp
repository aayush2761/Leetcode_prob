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
        if(!head || !head->next) return NULL;
        // first detrect the cycle 
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
            if(fast==slow) break;
        }
        // check valid fast 
        if(!fast || !fast->next) return NULL;
        // restart
        slow= head;
        while(slow!= fast){
            slow= slow->next;
            fast= fast->next;
        }
        return slow ;
    }
};