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
    ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=reverseLinkedList(l1);
        ListNode*temp2=reverseLinkedList(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        int carry = 0;
        // code
        while(temp1!=nullptr || temp2!=nullptr){
            int x1 = (temp1 != nullptr) ? temp1->val : 0;
            int x2 = (temp2 != nullptr) ? temp2->val : 0;
            int sum = x1 + x2 + carry;

            carry = sum / 10;
            res->next = new ListNode(sum % 10);
            res = res->next;
             if (temp1 != nullptr) temp1 = temp1->next;
            if (temp2 != nullptr) temp2 = temp2->next;
        }
        if(carry>0){
            res->next = new ListNode(carry);
            res = res->next;
        }
        return reverseLinkedList(dummy->next);

    }
};