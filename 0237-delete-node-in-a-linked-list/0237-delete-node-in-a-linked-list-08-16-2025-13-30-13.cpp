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
    void deleteNode(ListNode* node) {
        // overrriding concept 
        ListNode* prev= node;
        ListNode* dele = node;
        while(dele->next){
            dele->val= dele->next->val;
            prev= dele;
            dele= dele->next;
        }
        prev->next=NULL;
    }
};