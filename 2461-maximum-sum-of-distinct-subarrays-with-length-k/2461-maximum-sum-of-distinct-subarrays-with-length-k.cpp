class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, tempSum = 0;
        int i = 0, j = 0;
        unordered_map<int, int> mp;

        while (i < nums.size()) {
            int x = nums[i];
            mp[x]++;
            tempSum += x;

            while (mp[x] > 1) {
                tempSum -= nums[j];
                mp[nums[j]]--;
                j++;
            }

            if (i - j + 1 == k) {
                res = max(res, tempSum);
                tempSum -= nums[j];
                mp[nums[j]]--;
                j++;
            }

            i++;
        }

        return res;
    }
};
