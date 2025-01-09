class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m));
        
        dp[0][0] = {grid[0][0], grid[0][0]}; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue; 
                if (i == 0 && j != 0) {
                    long long a = (long long)grid[0][j] * dp[0][j - 1].first;
                    dp[0][j] = {a, a};
                } else if (i != 0 && j == 0) {
                    long long a = (long long)grid[i][0] * dp[i - 1][0].first;
                    dp[i][0] = {a, a};
                } else {
                    long long a1 = (long long)grid[i][j] * dp[i - 1][j].first;
                    long long a2 = (long long)grid[i][j] * dp[i - 1][j].second;
                    long long b1 = (long long)grid[i][j] * dp[i][j - 1].first;
                    long long b2 = (long long)grid[i][j] * dp[i][j - 1].second;
                    long long maxi = max({a1, a2, b1, b2});
                    long long mini = min({a1, a2, b1, b2});
                    dp[i][j] = {maxi, mini};
                }
            }
        }
        
        long long result = dp[n - 1][m - 1].first;
        return result < 0 ? -1 : result % 1000000007;
    }
};
