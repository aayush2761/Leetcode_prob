class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int id) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0 || vis[i][j]) 
            return 0;
        
        vis[i][j] = true;
        grid[i][j] = id;
        int size = 1 ;
        for (auto dir : directions) {
            int a = i + dir.first;
            int b = j + dir.second;
            size += dfs(a, b, grid, vis, id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        unordered_map<int, int>mp;
        int id = 2, maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int size = dfs(i, j, grid, vis, id);
                    mp[id] = size;
                    maxSize = max(maxSize, size);
                    id++;
                }
            }
        }
        int res = maxSize;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (auto dir : directions) {
                        int a = i + dir.first;
                        int b = j + dir.second;
                        if (a >= 0 && a < n && b >= 0 && b < n && grid[a][b] > 1) {
                            st.insert(grid[a][b]);
                        }
                    }
                    int newSize = 1;  // Count the flipped cell
                    for (auto id : st) {
                        newSize += mp[id];
                    }
                    res = max(res, newSize);
                }
            }
        }
        return res;
    }
};
