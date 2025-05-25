class Solution {
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void bfs(queue<pair<int, int>>& Positions, vector<vector<bool>>& visited, int startRow, int startCol, vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        visited[startRow][startCol] = true;
        Positions.push({startRow, startCol});

        // BFS traversal
        while (!Positions.empty()) {
            int size = Positions.size();
            for (int i = 0; i < size; i++) {
                auto current = Positions.front();
                Positions.pop();

                // Traverse all the directions 
                for (auto& dir : directions) {
                    int newRow = current.first + dir[0];
                    int newCol = current.second + dir[1];

                    // Conditions for boundary 
                    if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col &&
                        grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        Positions.push({newRow, newCol});
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // Base case 
        if (row == 0 && col == 0) return -1;

        // Visited array to keep track of the visited elements 
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        // BFS traversal 
        queue<pair<int, int>> Positions;
        int result = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                result++;
                bfs(Positions, visited, i, j, grid);
            }
        }
        return result;
    }
};
