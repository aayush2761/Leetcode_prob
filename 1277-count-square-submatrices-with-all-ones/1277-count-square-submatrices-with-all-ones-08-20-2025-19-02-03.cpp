class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // dp[i][j] -> number of square we are making by that index from 0,0 to i,j th index 
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) continue;
                if(i==0 || j==0) dp[i][j]=1;
                else{
                    dp[i][j] = 1+ min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
                total+= dp[i][j];
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";

            }
            cout<<endl;
         }
         return total;
    }
};