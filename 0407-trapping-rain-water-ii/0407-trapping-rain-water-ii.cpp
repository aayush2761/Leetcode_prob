class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis (n, vector<int> (m, 0));
        auto compare = [&] (auto a, auto b) {
            return get<2> (a) > get<2> (b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compare)> minHeap (compare);
        int maxCurrHeight = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    minHeap.push({i, j, grid[i][j]});
                    vis[i][j] = true;
                }
            }
        }
        vector<int> dirRow = {0, 0, 1, -1};
        vector<int> dirCol = {1, -1, 0, 0};
        int vol = 0;
        while(!minHeap.empty()) {
            auto [row, col, height] = minHeap.top();
            minHeap.pop();
            maxCurrHeight = max(maxCurrHeight, height);
            for(int i = 0; i < 4; i++) {
                int nx = row + dirRow[i];
                int ny = col + dirCol[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    minHeap.push({nx, ny, grid[nx][ny]});
                    vis[nx][ny] = true;
                    if(grid[nx][ny] < maxCurrHeight) {
                        vol += maxCurrHeight - grid[nx][ny];
                    }
                }
            }
        }
        return vol;
    }
};