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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *temp1=l1;
         ListNode *temp2=l2;
         if(l1==NULL && l2==NULL) return NULL;
        ListNode *l3 = new ListNode(0);
        ListNode *current = l3;
        int carry=0;
         while(temp1 || temp2 || carry){
             int sum = (temp1 ? temp1->val : 0) + (temp2 ? temp2->val : 0) + carry;

             carry=sum/10;
             int digit= sum%10;
            current->next = new ListNode(digit);
             current=current->next;
              if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
         } 
         return l3->next;     


    }
};