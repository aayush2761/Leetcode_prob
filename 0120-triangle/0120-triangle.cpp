//*********____------SPACE OPTIMIZATION-----**********//////
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
       vector<int>prev(m,0);
         vector<int>curr(m,0);
       for(int i=0;i<m;i++){
        prev[i]= triangle[m-1][i];
       }
       for(int i=m-2;i>=0;i--){
      
        for(int j=i;j>=0;j--){
            int down= triangle[i][j] + prev[j];
            int diag= triangle[i][j] + prev[j+1];
            curr[j]= min(down,diag);
        }
        prev=curr;
       }
       return prev[0];
    }
};






//*********____------Memoization-----**********//////

// class Solution {
// public:
//     int solve(vector<vector<int>>& triangle,int i, int j,int m, vector<vector<int>>&dp){
//         if(i==m-1 ) return triangle[i][j];

//         if(dp[i][j]!=-1) return dp[i][j];
//         int down= triangle[i][j] + solve(triangle, i+1,j,m,dp);
//         int diag= triangle[i][j] + solve(triangle, i+1,j+1,m,dp);

//         return dp[i][j]=  min(down,diag);

//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m= triangle.size();
//         vector<vector<int>>dp(m,vector<int>(m,-1));
//         return solve(triangle, 0,0,m,dp);
//     }
// };





//*********____------Recursion-----**********//////
// class Solution {
// public:
//     int solve(vector<vector<int>>& triangle,int i, int j,int m, int n){
//         if(i==m-1 ) return triangle[i][j];

//         int down= triangle[i][j] + solve(triangle, i+1,j,m,n);
//         int diag= triangle[i][j] + solve(triangle, i+1,j+1,m,n);

//         return min(down,diag);

//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m= triangle.size();
//         int n= triangle[0].size();
//         return solve(triangle, 0,0,m,n);
//     }
// };