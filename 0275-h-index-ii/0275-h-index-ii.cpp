class Solution {
public:
    int hIndex(vector<int>& v) {
        int lo = 0, n = v.size(), hi = v.size() - 1, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] >= n - mid) {
                ans = n - mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};