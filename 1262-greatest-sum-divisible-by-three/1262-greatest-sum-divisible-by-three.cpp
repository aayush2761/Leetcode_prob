class Solution {
public:
    int solve(int temp, vector<int>& nums, int i, vector<vector<int>>& dp) {
        if (i < 0) {
            return temp % 3 == 0 ? 0 : INT_MIN;
        }

        if (dp[i][temp % 3] != -1) return dp[i][temp % 3];

        int pick = nums[i]+solve((temp + nums[i])%3, nums, i - 1, dp);
        int nonPick = solve(temp%3, nums, i - 1, dp);

        return dp[i][temp % 3] = max(pick, nonPick);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(0, nums, n - 1, dp);
    }
};
