class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
        if(grid[0][0]==-1 || grid[row-1][col-1]==-1) return 0;
        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
        dp[row-1][col-1][col-1]=grid[row-1][col-1];
        for(int i=row-1;i>=0;i--){
            for(int j= col-1;j>=0;j--){
                for(int k= col-1;k>=0;k--){
                    int r2= i+j-k;
                    if(r2 < 0 || r2 >= row || grid[i][j] == -1 || grid[r2][k] == -1)continue;

                    if(i==row-1 && j==col-1 && k==col-1)continue;
                    // code 
                    // answer 
                    // int r2= i+j-k;
                    int answer=0;
                    if(grid[i][j]!=0)answer+= grid[i][j];
                    if(grid[r2][k]!=0 && (i!=r2 || j!=k))answer+= grid[r2][k];

                    //transitions 

                    // right right 
                    int rr=-1, rd=-1, dr=-1, dd=-1;
                    if(i+1<row && r2+1<row && dp[i+1][j][k]!=-1)rr= dp[i+1][j][k];
                    // right down 
                    if(i+1<row && k+1<col && dp[i+1][j][k+1]!=-1)rd= dp[i+1][j][k+1];
                    // down right
                    if(j+1<col && r2+1<row && dp[i][j+1][k]!=-1)dr= dp[i][j+1][k];
                    // down down 
                    if(j+1<col && k+1<col && dp[i][j+1][k+1]!=-1)dd= dp[i][j+1][k+1];

                    int best = max({rr, rd, dr, dd});
                    if(best != -1)
                        dp[i][j][k]= answer + best;
                }
            }
        }
        return max(0, dp[0][0][0]);
    }
};
