class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool present[n + 2]; // Auxiliary array to mark the presence of positive integers
        
        // Initialize present array elements to false
        for (int i = 0; i < n + 2; i++) {
            present[i] = false;
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n) {
                present[nums[i]] = true; // Mark the presence of positive integers in nums
            }
        }
        
        for (int j = 1; j <= n + 1; j++) {
            if (!present[j]) {
                return j; // Return the first missing positive integer
            }
        }
        
        return n + 1; // If all positive integers from 1 to n are present, return n + 1
    }
};
