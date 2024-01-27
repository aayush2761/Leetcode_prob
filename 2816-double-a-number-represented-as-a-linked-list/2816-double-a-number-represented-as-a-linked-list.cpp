class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head); 
        ListNode* temp = head;
        int carry = 0;
        while (temp != nullptr) {
            int doubledValue = temp->val * 2 + carry;
            temp->val = doubledValue % 10; 
            carry = doubledValue / 10;     
            temp = temp->next;            
        }
        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        return reverseList(head); 
    }
};
