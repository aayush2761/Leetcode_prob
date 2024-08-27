// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* temp = head;  // Start traversing from the head

//         while (temp != nullptr && temp->next!=nullptr) {
//             // int t = temp->val;  
//             // ListNode* curr = temp->next;   
//             // while (curr != nullptr && curr->val == t) {
//             //     curr = curr->next;
//             // }

           
//             // temp->next = curr;
//             // temp = curr;  
//             if (temp->val == temp->next->val) {
//                 temp->next = temp->next->next;
//             } else {
//                 temp = temp->next;
//             }
//         }

//         return head;  
//     }
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
