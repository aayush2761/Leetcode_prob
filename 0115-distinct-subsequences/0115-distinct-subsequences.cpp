
// //////////************______--------  SPACE OPTIMIZATION SOLUTION     ************______--------/////////

class Solution {
public:
    int numDistinct(string s, string t) {
        int m= s.size();
        int n= t.size();
        vector<double>prev(n+1,0), curr(n+1,0);

        // making one based indexing 
        // for(int i=0; i<=n;i++ ) prev[0]=1;
        //for(int j=1; j<=m;j++ ) dp[0][j]=0;

        prev[0]=1, curr[0]=1;

        // code 

        for(int i =1;i<=m;i++){
            for(int j=1;j<=n;j++){
                // recursive relations 
                //compare the previous guys 
                 if(s[i-1]==t[j-1]){
                   curr[j] = prev[j-1] + prev[j];
                }
                 else   curr[j] =prev[j];
               }
               prev=curr;
            }
        return (int)prev[n];
    }

};

// //////////************______--------  TABULATION SOLUTION     ************______--------/////////

// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int m= s.size();
//         int n= t.size();
//         vector<vector<double>>dp(m+1, vector<double>(n+1,0));

//         // making one based indexing 
//         for(int i=0; i<=m;i++ ) dp[i][0]=1;
//         //for(int j=1; j<=m;j++ ) dp[0][j]=0;

//         // code 

//         for(int i =1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 // recursive relations 
//                 //compare the previous guys 
//                  if(s[i-1]==t[j-1]){
//                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//                 }
//                  else   dp[i][j] =dp[i-1][j];
//                }
//             }
//         return (int) dp[m][n];
//     }

// };

// //////////************______--------  MEMOIZATION SOLUTION     ************______--------/////////

// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int i= s.size()-1;
//         int j= t.size()-1;
//                vector<vector<int>>dp(i+1, vector<int>(j+1,-1));
//         return utilFunction(s,t,i,j,dp);
//     }
// private:
//     int utilFunction(string &s, string &t , int i , int j ,  vector<vector<int>>&dp){
//         // base case 
//         if(j<0) return 1;
//         if(i<0) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
 
//         if(s[i]==t[j]){
//             return dp[i][j] = utilFunction(s,t, i-1, j-1, dp) + utilFunction(s,t, i-1, j,dp);
//         }
//         return dp[i][j] = utilFunction(s,t, i-1, j,dp);
//     }

// };

// //////////************______--------  RECURSIVE SOLUTION     ************______--------/////////



// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int i= s.size()-1;
//         int j= t.size()-1;
//         return utilFunction(s,t,i,j);
//     }
// private:
//     int utilFunction(string &s, string &t , int i , int j){
//         // base case 
//         if(j<0) return 1;
//         if(i<0) return 0;
        
        
//         if(s[i]==t[j]){
//             return utilFunction(s,t, i-1, j-1) + utilFunction(s,t, i-1, j);
//         }
//         return utilFunction(s,t, i-1, j);
//     }

// };