class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        int res = 0;
        int diff = INT_MAX;

        for (int i = 0; i < n; i++) {
            long long left = pref[i + 1] / (i + 1);
            long long right = (i == n - 1) ? 0 : (pref[n] - pref[i + 1]) / (n - i - 1);
            if (diff > abs(left - right)) {
                diff = abs(left - right);
                res = i;
            }
        }

        return res;
    }
};
