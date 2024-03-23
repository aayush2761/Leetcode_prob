class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return; // No need to reorder if the list has 0, 1, or 2 nodes
        
        // Step 1: Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode *prev = NULL, *curr = slow->next;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = NULL; // Break the link between the first and second halves
        
        // Step 3: Merge the two halves
        ListNode *p1 = head, *p2 = prev;
        while (p1 && p2) {
            ListNode *next1 = p1->next;
            ListNode *next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }
};
