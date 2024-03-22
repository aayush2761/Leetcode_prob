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
    bool isPalindrome(ListNode* head) {
        // Base cases
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the midpoint of the list
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *secondHalf = reverseList(slow->next);
        
        // Compare the first and second halves
        while (secondHalf != nullptr) {
            if (head->val != secondHalf->val)
                return false;
            head = head->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
