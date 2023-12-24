
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *previous=NULL,*current=head,*n=head->next;
        while(current!=NULL){
            current->next=previous;
            previous=current;
            current=n;
            if(n!=NULL){
                n=n->next;
            }
        }
        return previous;
    }
};