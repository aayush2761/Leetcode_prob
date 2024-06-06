// //////////************______--------  SPACE OPTIMIZATION SOLUTION     ************______--------/////////

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>prev(m+1,0) , curr(m+1 , 0);

        // base case 
        // 1 based indexing 

        //  // base_case-02  if(j<0) return i;
        // for(int i=0;i<=n;i++) dp[i][0]=i;
        // // base_case-01  if(i<0) return j;
        for(int j=0;j<=m;j++) prev[j]=j;

       
        
        

        // code part
        for(int i =1;i<=n;i++){
            // base case 02 from recursion
            curr[0]=i;
            for(int j=1;j<=m;j++){
                 if(word1[i-1]== word2[j-1]) curr[j]= prev[j-1];

                 else {
                   curr[j]=1+ min(
                   curr[j-1],    //INSERTION
                     min(  prev[j],    // DELETION
                       prev[j-1])); } // REPLACEMENT
            
            }
            prev=curr;
        }
        return prev[m];
    }
};



// //////////************______--------  TABULATION SOLUTION     ************______--------/////////



// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>>dp(n+1 , vector<int>(m+1,0));

//         // base case 
//         // 1 based indexing 

//          // base_case-02  if(j<0) return i;
//         for(int i=0;i<=n;i++) dp[i][0]=i;
//         // base_case-01  if(i<0) return j;
//         for(int j=0;j<=m;j++) dp[0][j]=j;
        
        

//         // code part
//         for(int i =1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                  if(word1[i-1]== word2[j-1]) dp[i][j]=0+ dp[i-1][j-1];

//                  else {
//                 dp[i][j]=1+ min(
//                    dp[i][j-1],    //INSERTION
//                   min(  dp[i-1][j],    // DELETION
//                     dp[i-1][j-1])); } // REPLACEMENT
            
//             }
//         }
//         return dp[n][m];
//     }
// };




// //////////************______--------  MEMOIZATION SOLUTION     ************______--------/////////



// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>>dp(n , vector<int>(m,-1));
//         return utilFunction(word1, word2 , n-1, m-1,dp);
//     }
// private: 
//     int utilFunction(string &word1, string &word2 , int i, int j ,vector<vector<int>>&dp){
//         // base cases 
//         if(i<0) return j+1;
//         if(j<0) return i+1;

//         if(dp[i][j]!=-1) return dp[i][j];
//         // code 
//         // matches 
//         if(word1[i]== word2[j]) return dp[i][j]=0+ utilFunction(word1, word2 , i-1, j-1,dp);

//         return dp[i][j]=min(
//            1 + utilFunction(word1, word2 , i, j-1 , dp),    //INSERTION
//            min( 1+ utilFunction(word1, word2 , i-1, j , dp),    // DELETION
//             1+ utilFunction(word1, word2 , i-1, j-1 ,dp))   // REPLACEMENT
//         );
//     }
// };



// //////////************______--------  RECURSIVE SOLUTION     ************______--------/////////



// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         return utilFunction(word1, word2 , n-1, m-1);
//     }
// private: 
//     int utilFunction(string &word1, string &word2 , int i, int j){
//         // base cases 
//         if(i<0) return j+1;
//         if(j<0) return i+1;

//         // code 
//         // matches 
//         if(word1[i]== word2[j]) return 0+ utilFunction(word1, word2 , i-1, j-1);

//         return min(
//            1 + utilFunction(word1, word2 , i, j-1),    //INSERTION
//            min( 1+ utilFunction(word1, word2 , i-1, j),    // DELETION
//             1+ utilFunction(word1, word2 , i-1, j-1))   // REPLACEMENT
//         );
//     }
// };