class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        waitCost[0][0] = 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e16));
        // dp[n - 1][m - 1] = 1LL * n * m;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = 1LL * (i + 1) * (j + 1);
                } else {
                    long long down = (i + 1 < n) ? dp[i + 1][j] : 1e16;
                    long long right = (j + 1 < m) ? dp[i][j + 1] : 1e16;
                    dp[i][j] = min(down, right) + waitCost[i][j] + 1LL * (i + 1) * (j + 1);
                }
            }
        }

        return dp[0][0];
    }
};