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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int c=1;
        ListNode* temp=head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
         temp=head;
        while (c > 1 && temp != nullptr && temp->next != nullptr) {
            ListNode* tempx = new ListNode();
            tempx->val = std::__gcd(temp->val, temp->next->val);
            
            ListNode* tempy = temp->next;
            temp->next = tempx;
            tempx->next = tempy;

            temp = temp->next->next;
            c--;
        }
        return head;

    }
};