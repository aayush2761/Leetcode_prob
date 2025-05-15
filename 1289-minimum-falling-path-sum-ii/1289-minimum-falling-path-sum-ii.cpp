class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // dp[i][j] -> minimumsum from last row to i,j th row 
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=n-1;i>=0;i--){
            for(int j=0 ; j<n;j++){
                if(i==n-1)dp[i][j]= grid[i][j];
                else{
                    for(int k=0;k<n;k++){
                        if(k!= j)dp[i][j]= min(dp[i][j], grid[i][j]+dp[i+1][k]);
                    }
                }
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};