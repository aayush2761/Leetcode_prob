

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for (auto i : nums) mp[i]++;
        
      
        while (head && mp.find(head->val) != mp.end()) {
            // ListNode* temp = head;
            head = head->next;
            // delete temp;
        }

        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current) {
            if (mp.find(current->val) != mp.end()) {
                ListNode* temp = current;
                if (prev) {
                    prev->next = current->next;
                }
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};