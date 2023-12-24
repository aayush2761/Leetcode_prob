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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if (!headA || !headB) {
            return nullptr;
        }
        ListNode *tempA=headA;
          ListNode *tempB=headB;
       while (tempA && tempB) {
            if (tempA == tempB) {
                return tempA;
            }

            tempA = tempA->next;
            tempB = tempB->next;
            if (!tempA && tempB) {
                tempA = headB;
            }

            if (!tempB && tempA) {
                tempB = headA;
            }
        }
        return NULL;
    }
};