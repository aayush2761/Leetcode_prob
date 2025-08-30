class Solution {
public:
    bool isValidRow(vector<vector<char>>& matrix, int r, int c){
        for(int i=0;i<9;i++){
            if(i!= c){
                if(matrix[r][i]== matrix[r][c]) return 0;
            }
        }
        return 1;
    }
    bool isValidCol(vector<vector<char>>& matrix, int r, int c){
        for(int i=0;i<9;i++){
            if(i!= r){
                if(matrix[i][c]== matrix[r][c]) return 0;
            }
        }
        return 1;
    }
    bool isValidBox(vector<vector<char>>& matrix, int r, int c){
        int rangeR = r/3 *3;
        int rangeC = c/3 *3;
        for(int i=rangeR;i<rangeR+3;i++){
            for(int j= rangeC; j<rangeC+3;j++){
                if(i!=r && j!=c ){
                    if(matrix[i][j]==matrix[r][c]) return 0;
                }
            }
        }
        return 1;
    }
    // bool isValidSudoku(vector<vector<char>>& matrix) {
    //     for(int i=0;i<matrix.size();i++){
    //         for(int j=0;j<matrix[0].size();j++){
    //             if( matrix[i][j]!='.')
    //                 if(!(isValidRow(matrix,i,j) && isValidCol(matrix,i,j) && isValidBox(matrix,i,j))) return 0;
    //         }
    //     }
    //     return 1;
    // }
    bool solve(vector<vector<char>>& board, int i, int j){
        if(i==9) return true; // solved entire board
        if(j==9) return solve(board, i+1, 0); // next row
        if(board[i][j] != '.') return solve(board, i, j+1); // skip filled

        for(int key=1; key<=9; key++){
            board[i][j] = key + '0';
            // if(isValidSudoku(board)){
            //     if(solve(board, i, j+1)) return true;
            // }
            if(isValidBox(board, i,j) && isValidCol(board, i,j) && isValidRow(board, i,j)){
                if(solve(board,i,j+1)) return true;
            }
            board[i][j] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};