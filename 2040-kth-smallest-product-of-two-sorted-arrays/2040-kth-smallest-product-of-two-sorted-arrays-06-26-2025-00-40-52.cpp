class Solution {
public:
    bool check(long long mid, vector<int>& nums1, vector<int>& nums2, long long k) {
        long long count = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int low = 0, high = nums2.size() - 1;
            int temp = 0;

            if (nums1[i] == 0) {
                if (mid >= 0) count += nums2.size();
                continue;
            }

            if (nums1[i] > 0) {
                while (low <= high) {
                    int midd = low + (high - low) / 2;
                    if ((long long)nums1[i] * nums2[midd] <= mid) {
                        temp = midd + 1;
                        low = midd + 1;
                    } else {
                        high = midd - 1;
                    }
                }
            } else {
                // nums1[i] < 0
                while (low <= high) {
                    int midd = low + (high - low) / 2;
                    if ((long long)nums1[i] * nums2[midd] <= mid) {
                        temp = nums2.size() - midd;
                        high = midd - 1;
                    } else {
                        low = midd + 1;
                    }
                }
            }

            count += temp;
        }
        return count >= k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long low = -1e10, high = 1e10;
        long long answer = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, nums1, nums2, k)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};
