class Solution {
public:
    int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    bool solve(vector<vector<char>>& board, string word, int index,int n, int i, int j,vector<vector<bool>>&visited ){
        if(index==n) return true;
        if(i== board.size()|| j== board[0].size() || i<0 || j<0) return false;
        
        if(board[i][j]!= word[index]|| visited[i][j]) return false;
        visited[i][j]= true;
        for(auto &dir : directions){
            int newi = dir[0]+i;
            int newj = dir[1]+j;
            if(solve(board, word, index+1, n, newi, newj,visited))return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(),0));
                if(solve(board,word,0,n, i,j,visited)) return 1;
            }
        }
        return 0;
    }
};