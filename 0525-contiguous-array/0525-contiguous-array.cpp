class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int temp = 0, maxLength = 0;
        mp[0] = -1; // Base case: balance 0 at index -1
        for (int i = 0; i < nums.size(); i++) {
            temp += (nums[i] == 0) ? -1 : 1;
            if (mp.find(temp) != mp.end()) {
                maxLength = max(maxLength, i - mp[temp]);
            } else {
                mp[temp] = i;
            }
        }
        return maxLength;
    }
};
