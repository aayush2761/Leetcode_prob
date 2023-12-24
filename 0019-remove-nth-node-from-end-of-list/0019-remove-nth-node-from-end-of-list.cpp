class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0 || head==nullptr) return head;

        ListNode* temp = head;
        int k = 0;

        while (temp != NULL) {
            temp = temp->next;
            k++;
        }

        temp = head;

        for (int i = 1; i < k - n; i++) {
            temp = temp->next;
        }

        if (k == n) {
            head = head->next;
        } else {
            temp->next = temp->next->next;
        }

        return head;
    }
};
