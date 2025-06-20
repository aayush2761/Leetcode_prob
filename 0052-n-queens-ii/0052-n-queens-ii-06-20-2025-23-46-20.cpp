class Solution {
public:
    void solve(vector<vector<string>>&res, int index, vector<string>&board, int n,unordered_set<int>&column,
                unordered_set<int>&leftDiag, unordered_set<int>&rightDiag){
        if(index==n) {
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            bool colFlag= false, leftDiagFlag= false, rightDiagFlag= false;
            if(column.find(i)== column.end()) colFlag= true;
            if(leftDiag.find(index-i)== leftDiag.end()) leftDiagFlag= true;
            if(rightDiag.find(i+index)== rightDiag.end()) rightDiagFlag= true;
            if(colFlag && leftDiagFlag && rightDiagFlag){
                board[index][i]='Q';
                column.insert(i);
                leftDiag.insert(index-i);
                rightDiag.insert(i+index);
                solve(res,index+1,board,n, column, leftDiag, rightDiag);
                board[index][i]='.';
                column.erase(i);
                leftDiag.erase(index-i);
                rightDiag.erase(i+index);
            }
        }
    }
    int totalNQueens(int n) {
         vector<vector<string>>res;
        // for check purpose 
        unordered_set<int>column, leftDiag,rightDiag;
        vector<string>board(n,string(n,'.'));
        solve(res,0,board,n, column, leftDiag, rightDiag);
        return res.size();
    }
};