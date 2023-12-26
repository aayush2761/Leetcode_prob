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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;      
        ListNode* p= head;
        while( p != NULL && p->next != NULL){
           swap(p->val,p->next->val);       
            if( p->next!=NULL)p=p->next->next;
        }
        return head;
    }
};