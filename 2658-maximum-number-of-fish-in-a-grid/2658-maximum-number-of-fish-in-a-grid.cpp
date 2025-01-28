class Solution {
public:
    const vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] == 0)
            return 0;
        vis[i][j] = true;
        int Count = grid[i][j];
        for (auto &k : directions) {
            Count += dfs(i + k[0], j + k[1], vis, grid);
        }
        return Count ;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int res =0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    res = max(res, dfs(i, j, vis, grid));
                }
            }
        }
        return res;
    }
};
