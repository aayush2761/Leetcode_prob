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
    // ListNode* reverse(ListNode* head){
    //     ListNode* prev = nullptr;
    //     ListNode* curr = head;
    //     while(curr){
    //         ListNode* nexx = curr->next;  // correctly get next node each time
    //         curr->next = prev;
    //         prev = curr;
    //         curr = nexx;
    //     }
    //     return prev;
    // }

    // QUESTION TOH DHANGG SE PADH LIYA KRO SIR JYADA HERO NA BNA KRO CH*T**E

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //  l1 = reverse(l1);
        //  l2 = reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;

         while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return (dummy->next);
    }
};
