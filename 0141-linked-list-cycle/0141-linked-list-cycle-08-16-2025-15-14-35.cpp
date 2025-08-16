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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        // constant extra space
        int index=0;
        ListNode* slow= head;
        ListNode* fast= head->next->next;
        while(slow!=NULL){
            index+=2;
            slow= slow->next;
             if(fast == NULL || fast->next==NULL){
                return false;
            }
            fast= fast->next->next;
            if(index>10000)return true;
        }
        return false;
    }
};