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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;  // To keep track of the end of the merged list
        ListNode* temp = head->next; // Start from the node after the initial 0
        int sum = 0;

        while (temp != NULL) {
            if (temp->val == 0) {
                ListNode* t = new ListNode(sum);
                current->next = t;
                current = current->next; // Move the current pointer
                sum = 0;
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
