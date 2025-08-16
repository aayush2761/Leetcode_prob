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
        // node where cycle begins 
        set<ListNode*>st;
        ListNode* slow= head;
        // ListNode* fast= head;
        while(slow){
            st.insert(slow);
            slow= slow->next;
            // fast= fast->next->next;
            if(st.count(slow)) return slow;
        }
        return NULL;
    }
};