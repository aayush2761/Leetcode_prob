class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head; // Handling edge cases
        
        int n = 1; // Counting the number of nodes
        ListNode* tail = head; // Finding the tail of the list
        while (tail->next != nullptr) {
            n++;
            tail = tail->next;
        }
        
        k = k % n; // Adjusting k if it's greater than the length of the list
        
        if (k == 0) return head; // If k is a multiple of n, no rotation needed
        
        ListNode* new_tail = head; // Finding the new tail after rotation
        for (int i = 1; i < n - k; i++) {
            new_tail = new_tail->next;
        }
        
        ListNode* new_head = new_tail->next; // New head after rotation
        new_tail->next = nullptr; // Breaking the link to form a new tail
        tail->next = head; // Joining the original tail to the original head to form a circular list
        
        return new_head;
    }
};
