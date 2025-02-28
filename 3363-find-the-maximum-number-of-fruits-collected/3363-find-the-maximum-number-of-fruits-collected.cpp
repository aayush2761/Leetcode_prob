class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        // The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1)
        int res=0;
        int n =grid.size();
        for(int i=0;i<n;i++){
            res+= grid[i][i];
            grid[i][i]=0;
        } 
        // for top left 
        // dp state -> maximum sum from 0,n-1 to i,j 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int c2 = solve(0, n-1, grid, n, n-1, dp);
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        int c3 = solve1(n-1, 0, grid, n, n-1, dp1); 
        return res+c3+c2;

    }
    int solve(int r, int c, vector<vector<int>>& grid, int n, int threshold, vector<vector<int>>& dp) {
        if (r == n-1 && c == n-1) return 0;
        if (c < n / 2 || threshold <= 0) return -1e9;
        if (dp[r][c] != -1) return dp[r][c];
        
        int res = INT_MIN;
        for (int j=-1; j<=1; j++) {
            int newR = r + 1;
            int newC = c + j;
            if (newR < n && newC < n) {
                res = max(res, grid[r][c] + solve(newR, newC, grid, n, threshold - 1, dp));
            }
        }
        return dp[r][c] = res;
    }
    int solve1(int r, int c, vector<vector<int>>& grid, int n, int threshold, vector<vector<int>>& dp1) {
        if (r == n-1 && c == n-1) return 0;
        if (r < n / 2 || threshold <= 0) return -1e9;
        if (dp1[r][c] != -1) return dp1[r][c];

        int res = INT_MIN;
        for (int i=-1; i<=1; i++) {
            int newR = r + i;
            int newC = c + 1;
            if (newR < n && newC < n) {
                res = max(res, grid[r][c] + solve1(newR, newC, grid, n, threshold - 1, dp1));
            }
        }
        return dp1[r][c] = res;

    }
};