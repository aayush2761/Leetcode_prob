class Solution {
public:
    void zero(vector<vector<int>>& matrix, int row, int col) {
        // for row
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[row][j] = 0;  // Fix: zero out the entire row
        }
        // for column
        for(int i = 0; i < matrix.size(); i++) {
            matrix[i][col] = 0;  // Fix: zero out the entire column
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        // get all zero positions 
        vector<pair<int, int>> pos;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) pos.push_back({i, j});
            }
        }
        // set zero 
        for(auto &i : pos) {
            zero(matrix, i.first, i.second);
        }
    }
};
