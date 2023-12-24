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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* c = head;
        while (c != NULL && c->next!=NULL ) {
            if (c->val == c->next->val) {
                c->next = c->next->next;
            } 
            else {
                c =c->next;
            }
        }

        return head;
    }
};
