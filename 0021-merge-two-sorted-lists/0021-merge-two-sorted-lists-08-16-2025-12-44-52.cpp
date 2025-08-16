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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr= dummy;
        ListNode* temp1= list1;
        ListNode* temp2= list2;
        while(temp1 && temp2){
            ListNode* node= new ListNode();
            if(temp1->val<= temp2->val){
                node->val= temp1->val;
                temp1= temp1->next;
            }
            else{
                node->val= temp2->val;
                temp2= temp2->next;
            }
            curr->next= node;
            curr= curr->next;
        }
        while(temp1){
            ListNode* node= new ListNode();
            node->val= temp1->val;
            temp1= temp1->next;
            curr->next= node;
             curr= curr->next;
        }
        while(temp2){
            ListNode* node= new ListNode();
            node->val= temp2->val;
            temp2= temp2->next;
            curr->next= node;
             curr= curr->next;
        }
        return dummy->next;
    }
};