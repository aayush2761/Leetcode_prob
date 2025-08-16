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
        ListNode* dummy = new ListNode();
        ListNode* curr= dummy;
        int carry=0;
        ListNode* t1= l1;
        ListNode* t2= l2;
        while(t1 && t2){
            int x = carry + t1->val+ t2->val;
            carry = x/10;
            x%=10;
            ListNode* t= new ListNode(x);
            curr->next= t;
            curr= curr->next;
            t1= t1->next;
            t2= t2->next;
        }
        while(t1){
             int x = carry + t1->val;
            carry = x/10;
            x%=10;
            ListNode* t= new ListNode(x);
            curr->next= t;
            curr= curr->next;
            t1= t1->next;
            // t2= t2->next;
        }
        while(t2){
             int x = carry + t2->val;
            carry = x/10;
            x%=10;
            ListNode* t= new ListNode(x);
            curr->next= t;
            curr= curr->next;
            // t1= t1->next;
            t2= t2->next;
        }
        // carry remaining 
        if(carry>0){
            int x = carry ;
            carry = x/10;
            x%=10;
            ListNode* t= new ListNode(x);
            curr->next= t;
            curr= curr->next;
        }
    
        return dummy->next;

    }
};