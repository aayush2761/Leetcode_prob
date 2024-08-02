class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        for (auto i : nums) {
            if (i == 1) one++;
        }
        if (one == 0 || one == n) return 0;
        for (int i = 0; i < one; i++) {
            nums.push_back(nums[i]);
        }
        int i = 0, j = 0, res = INT_MAX, count = 0;
        // fixed sized sliding window 
        while (i < one) {
            if (nums[i] == 1) count++;
            i++;
        }
        res = min(res, one - count);
        while (i < nums.size()) {
            if (nums[i] == 1) count++;
            if (nums[j] == 1) count--;
            res = min(res, one - count);
            i++;
            j++;
        }

        return res;
    }
};
