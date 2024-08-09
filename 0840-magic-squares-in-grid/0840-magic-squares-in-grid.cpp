class Solution {
public:
    bool solve(int srow, int scol, int erow, int ecol, vector<vector<int>>& grid) {
        vector<bool> v(10, false); // Using 10 instead of 9 for 1-indexed array
        // Check if all numbers are unique and between 1 and 9
        for (int i = srow; i <= erow; i++) {
            for (int j = scol; j <= ecol; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || v[num]) return false;
                v[num] = true;
            }
        }

        // Check the sum of rows, columns, and diagonals
        int sum = grid[srow][scol] + grid[srow][scol + 1] + grid[srow][scol + 2];
        
        for (int i = srow; i <= erow; i++) {
            if (grid[i][scol] + grid[i][scol + 1] + grid[i][scol + 2] != sum)
                return false;
        }

        for (int j = scol; j <= ecol; j++) {
            if (grid[srow][j] + grid[srow + 1][j] + grid[srow + 2][j] != sum)
                return false;
        }

        if (grid[srow][scol] + grid[srow + 1][scol + 1] + grid[srow + 2][scol + 2] != sum)
            return false;

        if (grid[srow][scol + 2] + grid[srow + 1][scol + 1] + grid[srow + 2][scol] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (solve(i, j, i + 2, j + 2, grid)) res++;
            }
        }
        return res;
    }
};
