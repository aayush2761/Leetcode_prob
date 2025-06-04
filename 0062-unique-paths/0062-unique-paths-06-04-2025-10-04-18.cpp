class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] -> number of unique path to reach n,m from i , j it index 
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                else {
                    if(i == n-1 && j+1 <m) dp[i][j]= dp[i][j+1];
                    else if(j==m-1 && i+1 <n)dp[i][j]= dp[i+1][j];
                    else if(i+1 < n && j+1 <m)dp[i][j]= dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};