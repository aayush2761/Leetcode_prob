class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // state 
        // dp[i][j] -> minimum health required to reach thr princess position from i,j to n-1 ,m-1;
        int n = dungeon.size();
        int m = dungeon[0].size();
        if(m==n && m==1){
            if(dungeon[0][0]>0) return 1;
            else return abs(dungeon[0][0])+1;
        }
        vector<vector<int>>dp(n,vector<int>(m,1000001));
         for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                } else if (i == n - 1) {
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                } else if (j == m - 1) {
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                } else {
                    int nextHealth = min(dp[i + 1][j], dp[i][j + 1]);
                    dp[i][j] = max(1, nextHealth - dungeon[i][j]);
                }
            }
         }
         return abs(dp[0][0]);

    }
};