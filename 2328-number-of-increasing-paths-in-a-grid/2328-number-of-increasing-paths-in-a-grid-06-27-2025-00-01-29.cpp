class Solution {
public:
 int directions[4][2]={{-1,0}, {1,0}, {0,-1},{0,1}};
     int mod= 1000000007;
   int dfs(int row, int col, int n, int m , vector<vector<int>>&dp, vector<vector<int>>&matrix ){
        if(dp[row][col]!=-1) return dp[row][col];

        // conditions 
        // vis[row][col]=1;
        int answer=1;
        for(auto & it : directions){
            int nr= row + it[0];
            int nc= col + it[1];
            if(nr>=0 && nr<n && nc>=0 && nc<m ){
                if(matrix[row][col]< matrix[nr][nc]) answer= max(1+dfs(nr,nc,n,m,dp,matrix), answer);
            }

        }
        return dp[row][col]= answer;
    }
    int countPaths(vector<vector<int>>& matrix) {
       int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    dfs(i,j,n,m,dp,matrix);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res= (res+ dp[i][j])%mod;
            }
        }
        return res;
    }
};