/////**********____-----SPACE OPTIMIZATIOIN SOLUTION-------_________*********//////

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
       vector<int>prev(n,0) , curr(n,0);


        for(int j =0 ; j<n;j++) prev[j]= matrix[0][j];
        for( int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                 int up= matrix[i][j]+prev[j];
                 int left= matrix[i][j];
                 if(j-1>=0) left+=prev[j-1];
                 else left+= 1e9;
                 int right= matrix[i][j];
                 if(j+1<n) right+=prev[j+1];
                 else right+=1e9;
                curr[j] =  min(up, min(left,right));
            }
            prev=curr;
        }

        int answer=INT_MAX;
        for(int j =0 ; j<n;j++){
            answer= min(answer, prev[j]);
        }
        return answer;
    }
};



/////**********____----- TABULATION SOLUTION-------_________*********//////


// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n= matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         for(int j =0 ; j<n;j++) dp[0][j]= matrix[0][j];
//         for( int i=1;i<n;i++){
//             for(int j=0;j<n;j++){
//                  int up= matrix[i][j]+dp[i-1][j];
//                  int left= matrix[i][j];
//                  if(j-1>0) left+=dp[i-1][j-1];
//                  else left+= 1e9;
//                  int right= matrix[i][j];
//                  if(j+1<n) right+=dp[i-1][j+1];
//                  else right+=1e9;
//                  dp[i][j] =  min(up, min(left,right));
//             }
//         }

//         int answer=INT_MAX;
//         for(int j =0 ; j<n;j++){
//             answer= min(answer, dp[n-1][j]);
//         }
//         return answer;
//     }
// };

/////**********____----- MEMOIZATION SOLUTION-------_________*********//////

// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n= matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         for(int j =0 ; j<n;j++) dp[0][j]= matrix[0][j];
//         for( int i=1;i<n;i++){
//             for(int j=0;j<n;j++){
//                  int up= matrix[i][j]+dp[i-1][j];
//                  int left= matrix[i][j];
//                  if(j-1>0) left+=dp[i-1][j-1];
//                  else left+= 1e9;
//                  int right= matrix[i][j];
//                  if(j+1<n) right+=dp[i-1][j+1];
//                  else right+=1e9;
//                  dp[i][j] =  min(up, min(left,right));
//             }
//         }

//         int answer=INT_MAX;
//         for(int j =0 ; j<n;j++){
//             answer= min(answer, dp[n-1][j]);
//         }
//         return answer;
//     }
// };


/////**********____----- MEMOIZATION SOLUTION-------_________*********//////

// class Solution {
// public:
//     int minimumPath(vector<vector<int>>& matrix, int i, int j , int m ,vector<vector<int>>&dp){
//         if(j<0 || j>m-1) return 1e9+7;
//         if(i==0) return matrix[i][j];

//         if(dp[i][j]!=-1) return dp[i][j];
//         int up= matrix[i][j]+ minimumPath(matrix, i-1,j,m,dp);
//         int left= matrix[i][j]+ minimumPath(matrix, i-1,j-1,m,dp);
//         int right= matrix[i][j]+ minimumPath(matrix, i-1,j+1,m,dp);

//         return dp[i][j] =  min(up, min(left,right));

//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n= matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         int answer=INT_MAX;
//         for(int j =0 ; j<n;j++){
//             int p= minimumPath(matrix, n-1 ,j , n,dp);
//         answer= min(answer,p );
//         }
//         return answer;
//     }

// };
// TC: O(N*N) due to three path options 
// SC: O(N)+ O(N*N) Recursive Stack SPace + DP Vector MAtrix Spoace



// ---------------------------------------------------------------------------------------


/////**********____----- ReCURSIVE SOLUTION-------_________*********//////

// class Solution {
// public:
//     int minimumPath(vector<vector<int>>& matrix, int i, int j , int m){
//         if(j<0 || j>m-1) return 1e9+7;
//         if(i==0) return matrix[i][j];

//         int up= matrix[i][j]+ minimumPath(matrix, i-1,j,m);
//         int left= matrix[i][j]+ minimumPath(matrix, i-1,j-1,m);
//         int right= matrix[i][j]+ minimumPath(matrix, i-1,j+1,m);

//         return min(up, min(left,right));

//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n= matrix.size();
//         int answer=INT_MAX;
//         for(int j =0 ; j<n;j++){
//             int p= minimumPath(matrix, n-1 ,j , n);
//         answer= min(answer,p );
//         }
//         return answer;
//     }

// };

// TC: O(3^n) due to three path options 
// SC: O(N) Recursive Stack SPace 