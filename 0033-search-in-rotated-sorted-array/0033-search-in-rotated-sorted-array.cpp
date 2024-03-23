class Solution {
public:
    // Binary search function
    int search(vector<int>& arr, int low, int high, int key) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // Main function
    int search(vector<int>& nums, int target) {
        // Base cases 
        if (nums.size() == 0) return -1;
        if (nums.size() == 1 && nums[0] != target) return -1;
        if (nums.size() == 2 && nums[0] != target && nums[1] != target) return -1;

        int l = 0;
        int h = nums.size() - 1;
        int p = 0, q = nums.size() - 1;
        int index = 0;

        while (p <= q) {
            int mid = p + (q - p) / 2;
            if (nums[mid] < nums[(mid - 1 + nums.size()) % nums.size()] && 
                nums[mid] < nums[(mid + 1) % nums.size()]) {
                index = mid;
                break;
            } else if (nums[mid] >= nums[l]) {
                p = mid + 1;
            } else {
                q = mid - 1;
            }
        }

        // Binary search in both sub-arrays
        int res = search(nums, l, index - 1, target);
        if (res != -1) return res;
        return search(nums, index, h, target);
    }
};
