class Solution {
public:
    int findMin(vector<int>& nums) {
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
        return nums[index];
    }
};