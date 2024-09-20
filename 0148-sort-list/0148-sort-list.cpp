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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode*temp= head;
        while(temp!=NULL){
            int t=temp->val;
            v.push_back(t);
            temp=temp->next;

        }
        sort(v.begin(),v.end());
        ListNode*dummy= new ListNode(0);
        ListNode* current = dummy;  
         for(auto i : v) {
             ListNode* t = new ListNode(i);  
             current->next = t; 
             current = current->next;  
         }
         return dummy->next;
    }
};