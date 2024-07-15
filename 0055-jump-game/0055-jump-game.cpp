class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, -1); // Use -1 for unvisited, 0 for false, 1 for true
        return helper(0, size, nums, dp);
    }

    bool helper(int ind, int n, vector<int>& nums, vector<int>& dp) {
        // base case 
        if (ind >= n - 1) return true;
        
        // If already visited and the value is computed, return it
        if (dp[ind] != -1) return dp[ind] == 1;
        
        for (int i = 1; i <= nums[ind]; i++) {
            // call each function 
            if (helper(ind + i, n, nums, dp)) {
                dp[ind] = 1;
                return true;
            }
        }

        dp[ind] = 0;
        return false;
    }
};
