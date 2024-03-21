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
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode*temp= head;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=v.size()-1;
        int sum=0;
        while(i<=j){
            sum= max(sum,(v[i]+v[j]));
            i++;
            j--;
        }
        return sum;
    }
};