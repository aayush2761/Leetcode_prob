class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> minRow(matrix.size(), INT_MAX);
        vector<int> maxCol(matrix[0].size(), INT_MIN);

        // Find the minimum element in each row
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                minRow[i] = min(matrix[i][j], minRow[i]);
            }
        }

        // Find the maximum element in each column
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int i = 0; i < matrix.size(); ++i) {
                maxCol[j] = max(matrix[i][j], maxCol[j]);
            }
        }

        // Check for lucky numbers
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};
