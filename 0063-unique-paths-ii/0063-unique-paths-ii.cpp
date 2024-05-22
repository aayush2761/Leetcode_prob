// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n= obstacleGrid[0].size();
//         vector<int>prev(m , 0);
//         for(int i=0;i<m-1;i++){
//             vector<int>temp(n,0);
//             for(int j=0;j<n-1;j++){
//                 if(i==0 && j==0) temp[j]=0;
//                 else {
//                    if(temp[j]!=1 && temp[j+1]!=1) temp[j]= prev[j]+ temp[j-1];
//                 }
//             }
//              prev=temp;
//         }
//          return prev[n-1];
//     }
// };



// ********Memoization***************


// class Solution {
// public:
//      int totalPath(int i, int j , vector<vector<int>>&dp , vector<vector<int>>& obstacleGrid){
//         if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
//         if(i==0 && j==0) return 1;
//         if(i<0 || j<0) return 0;
       
//         if(dp[i][j]!=-1) return dp[i][j];

//         int up= totalPath(i-1,j,dp,obstacleGrid);
//         int left= totalPath(i,j-1,dp,obstacleGrid);
//         return dp[i][j]= up+ left;

//     } 
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//         int n= obstacleGrid[0].size();
//         // if(m==1 && n==1 && obstacleGrid[0][0]==1) return 0;
//         //   if(m==1 && n==1 && obstacleGrid[0][0]==0) return 1;
//         vector<vector<int>>dp(m, vector<int>(n,-1));
//          return totalPath(m-1,n-1,dp,obstacleGrid);
//     }
// };



class Solution {
public:
     
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
        int n= obstacleGrid[0].size();
        // if(m==1 && n==1 && obstacleGrid[0][0]==1) return 0;
        //   if(m==1 && n==1 && obstacleGrid[0][0]==0) return 1;
        vector<vector<int>>dp(m, vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(i >= 0 && j >= 0 && obstacleGrid[i][j]==1) {dp[i][j] = 0;; continue;}
                  if(i==0 && j==0 ) {
                     dp[i][j] = 1; 
                    continue;
                    }
                 
                    int up=0,left=0;
                    if(i>0)  up= dp[i-1][j];
                    if(j>0) left= dp[i][j-1];
                    dp[i][j]= up+left;
                 
            }
        }
        return dp[m-1][n-1];
    }
};