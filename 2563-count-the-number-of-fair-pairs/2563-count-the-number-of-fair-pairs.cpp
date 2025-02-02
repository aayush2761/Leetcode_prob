class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int reql = lower - nums[i];
            int reqr = upper - nums[i];
            int lindex = lower_bound(nums.begin() + i + 1, nums.end(), reql) - nums.begin();
            int rindex = upper_bound(nums.begin() + i + 1, nums.end(), reqr) - nums.begin();
            res += rindex - lindex;
        }
        return res;
    }
};
