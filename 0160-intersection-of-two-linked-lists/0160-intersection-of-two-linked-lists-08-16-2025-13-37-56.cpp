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
        set<ListNode*>st;
        ListNode* temp= headA;
        while(temp){
            st.insert(temp);
            temp=temp->next;

        }
        // check 
        ListNode* t= headB;
        while(t){
            if(st.count(t)) return t;
            t= t->next;
        }
        return NULL;
    }
};