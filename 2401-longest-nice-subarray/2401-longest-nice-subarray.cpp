class Solution {
public:
    int check(int count, vector<int>& nums, int n) {
        // int i = 0, j = 0;
        // while (i < n) {
        //     if (i - j + 1 == mid) {
        //         for (int k = j; k <= i; k++) {
        //             for (int l = k + 1; l <= i; l++) {
        //                 if ((nums[k] & nums[l]) != 0) return 0;
        //             }
        //         }
        //         j++; // Move the window forward
        //     }
        //     i++;
        // }
        // return 1;
        int start = 0;
    while (start + count - 1 < nums.size()) {
        int end = start + count - 1;
        bool found = true;
        for (int i = start; i < end; i++) {
            for (int j = i + 1; j <= end; j++) {
                if ((nums[i] & nums[j]) != 0) {
                    found = false;
                    break;
                }
            }
            if (!found) break;
        }
        if (found) return true;
        start++;
    }
    return false;
    }

    int longestNiceSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int lo = 1;
        int hi = max(32,n);
        int ans = lo;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, nums, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
