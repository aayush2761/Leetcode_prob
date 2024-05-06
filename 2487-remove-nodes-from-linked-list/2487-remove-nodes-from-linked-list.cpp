class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode;

        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev; 
    }

    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* temp = reverse(head);
        ListNode* newHead = temp;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val < temp->val) {
                ListNode* temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
            } else {
                temp = temp->next;
            }
        }
        return reverse(newHead); 
    }
};
