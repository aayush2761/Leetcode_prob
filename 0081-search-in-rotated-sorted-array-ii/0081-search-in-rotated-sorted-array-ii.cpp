class Solution {
public:
    bool bs(int low, int high, vector<int>& nums, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return bs(0,nums.size()-1,nums,target);
    }
};