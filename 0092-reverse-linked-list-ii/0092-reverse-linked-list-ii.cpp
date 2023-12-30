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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l= head;
        ListNode* r= head;
       if(left>right)return head;
       int x=left;
       int y=right;
        while(x>1){
            l=l->next;
            x--;
        }
        while(y>1){
            r=r->next;
            y--;
        }
           if(l!=nullptr && r!=nullptr) swap(l->val,r->val);
            left++;
            right--;
        return reverseBetween(head,left,right);
    }
};