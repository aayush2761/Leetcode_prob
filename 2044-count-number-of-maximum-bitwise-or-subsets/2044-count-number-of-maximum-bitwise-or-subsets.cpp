class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        int n = nums.size();

        // Calculate the OR for every subset
        for (int i = 0; i < (1 << n); ++i) {  // Iterate over all subsets
            int temp = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    temp |= nums[j];  // If j-th bit is set, include nums[j]
                }
            }
            mp[temp]++;
            res = max(res, temp);
        }

        // Return the count of subsets that achieve the maximum OR value
        return mp[res];
    }
};
