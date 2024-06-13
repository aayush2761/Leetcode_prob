class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(nums1.begin(), nums1.begin() + m); // Copy first m elements of nums1 to v

        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (v[i] <= nums2[j]) { // Ensure non-decreasing order
                nums1[k] = v[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m) {
            nums1[k] = v[i];
            i++;
            k++;
        }
        while (j < n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
