class Solution {
public:
    bool isValid(vector<string>&board, int row, int col,int n){
       // for row 
       for(int i=row-1;i>=0;i--){
        if(board[i][col]=='Q') return 0;
       }
       // col
       for(int i=col-1;i>=0;i--){
        if(board[row][i]=='Q') return 0;
       }
       // upward right diagonal 
       //row-1, col+1
       int i = row-1 , j= col+1;
       while(i>=0 && col<n){
            if(board[i][j]=='Q') return 0;
            i--;
            j++;
       }
       // upward left 
       i = row-1 , j= col-1;
       while(i>=0 && j>=0){
            if(board[i][j]=='Q') return 0;
            i--;
            j--;
       }
       return 1;
    }
    void solve(vector<vector<string>>&res, int index, vector<string>&board, int n){
        if(index==n) {
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(board, index, i,n)){
                board[index][i]='Q';
                solve(res,index+1,board,n);
                board[index][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        solve(res,0,board,n);
        return res;
    }
};