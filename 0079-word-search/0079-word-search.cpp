class Solution {
public:
    bool dfs( vector<vector<char>>& board,int i,int j,int index, vector<vector<bool>>&vis,string& word){
        if(index==word.length()-1) return true;

        vis[i][j]=true;
        int row= board.size(),col=board[0].size();

        //traversal 

        if(i-1>=0 && !vis[i-1][j] && board[i-1][j]==word[index+1] && dfs(board,i-1,j,index+1,vis,word))
        return true;
         if(i+1<=row-1 && !vis[i+1][j] && board[i+1][j]==word[index+1] && dfs(board,i+1,j,index+1,vis,word))
        return true;
         if(j-1>=0 && !vis[i][j-1] && board[i][j-1]==word[index+1] && dfs(board,i,j-1,index+1,vis,word))
        return true;
         if(j+1<=col-1 && !vis[i][j+1] && board[i][j+1]==word[index+1] && dfs(board,i,j+1,index+1,vis,word))
        return true;

        vis[i][j]=false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row= board.size(),col=board[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0] && dfs(board,i,j,0,vis,word)) return true;
            }
        }
        return false;
    }
};


//backtrack+2D best Q