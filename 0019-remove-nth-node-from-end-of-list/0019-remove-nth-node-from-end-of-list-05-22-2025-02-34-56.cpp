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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // base cases
        if(head==NULL) return nullptr;
        if(head->next == NULL){
            if(n==1)return nullptr;
            else return head;
        }
        int total =0;
        ListNode* temp=head;
        while(temp){
            total++;
            temp=temp->next;
        }
        if(total ==n) return head->next;
        // cout<<total<<endl;
        temp=head;
        int step= total-n-1;
        while(step>0){
            temp=temp->next;
            step--;
        }
        cout<<temp->val<<endl;
        if(temp->next!=NULL)temp->next= temp->next->next;
        return head;

    }
};