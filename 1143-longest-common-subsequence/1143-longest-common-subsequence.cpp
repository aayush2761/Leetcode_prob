 class Solution {
public:
  
   int longestCommonSubsequence(string text1, string text2) {
        int index1= text1.size();
        int index2= text2.size();
        vector<int>prev(index2+1,0), curr(index2+1,0);
        // base case 
        // for(int i =0;i<=index1;i++) dp[i][0]=0;
        for(int i =0;i<=index2;i++) prev[i]=0;

        // changeing parameret 
        for(int i=1;i<=index1;i++){
            for(int j=1;j<=index2;j++){
                // copy the recursioin
                 if(text1[i-1]== text2[j-1]){
                     curr[j]= 1+ prev[j-1];
            
                 }
               // unmatch case
            else curr[j]= 0+ max(curr[j-1] ,  prev[j]);
            }
            prev=curr;
        
        }
       return prev[index2];
    }
};
/***********_____----- TABULATIONSOLUTION ______----------******/////////

//    int longestCommonSubsequence(string text1, string text2) {
//         int index1= text1.size();
//         int index2= text2.size();
//         vector<vector<int>>dp(index1+1 , vector<int>(index2+1, -1));
//         // base case 
//         for(int i =0;i<=index1;i++) dp[i][0]=0;
//         for(int i =0;i<=index2;i++) dp[0][i]=0;

//         // changeing parameret 
//         for(int i=1;i<=index1;i++){
//             for(int j=1;j<=index2;j++){
//                 // copy the recursioin
//                  if(text1[i-1]== text2[j-1]){
//                      dp[i][j]= 1+ dp[i-1][j-1];
            
//                  }
//                // unmatch case
//             else dp[i][j]= 0+ max(dp[i][j-1] ,  dp[i-1][j]);
//             }
//         }
//        return dp[index1][index2];
//     }
// };



/***********_____----- memoization SOLUTION ______----------******/////////

// class Solution {
// public:
//     int utilFunction( string  &text1, string &text2 ,int index1, int index2 , vector<vector<int>>&dp ){
//         if(index1<0 || index2<0){
//             return 0;
//         }

//         if(dp[index1][index2]!= -1) return dp[index1][index2]; 
//         // match case 
//         if(text1[index1]== text2[index2]){
//               return dp[index1][index2]= 1+ utilFunction(text1, text2 ,index1-1, index2-1,dp );
            
//         }
//         // unmatch case
//          return dp[index1][index2]= 0+ max(utilFunction(text1, text2 ,index1-1, index2 , dp ),utilFunction(text1, text2 ,index1, index2-1, dp ));

                  
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int index1= text1.size()-1;
//         int index2= text2.size()-1;
//         vector<vector<int>>dp(index1+1 , vector<int>(index2+1, -1));
//         return utilFunction(text1, text2 ,index1, index2 , dp );
//     }
// };
 

//***********_____----- RECURSIVE SOLUTION ______----------******/////////

// class Solution {
// public:
//     int utilFunction( string text1, string text2 ,int index1, int index2 ){
//         if(index1<0 || index2<0){
//             return 0;
//         }

//         // match case 
//         if(text1[index1]== text2[index2]){
//             return 1+ utilFunction(text1, text2 ,index1-1, index2-1 );
//         }
//         // unmatch case
//         return 0+ max(utilFunction(text1, text2 ,index1-1, index2 ),utilFunction(text1, text2 ,index1, index2-1 ));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int index1= text1.size()-1;
//         int index2= text2.size()-1;
//         return utilFunction(text1, text2 ,index1, index2 );
//     }
// };