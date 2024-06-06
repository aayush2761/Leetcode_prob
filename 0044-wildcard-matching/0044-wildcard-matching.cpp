class Solution {
public:
    bool isMatch(string s, string p) {
        string s1= p;
        string s2= s;
        int  n= s1.size();
        int m= s2.size();
          vector<bool>prev(m+1,false) , curr(m+1, false);

          // base case 1 (i<0 && j<0) return true;
          // base case 2 (i>=0 && j<0) return false;

            prev[0] = true;
           for (int j = 1; j <= m; j++) {
               prev[j] = false;
           }

        for (int i = 1; i <= n; i++) {
            // asssign before entgerikng avery curr 
            bool flag=true;
             for(int k=1;k<=i;k++){
                if(s1[k-1]!='*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?') {
                curr[j] = prev[j - 1];
            } else {
                if (s1[i - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
        }
        prev=curr;
    }

    // The value at dp[n][m] contains whether S1 matches S2
    return prev[m];
    }

};

///////////******______----------- TABULATION SOLUTION --------___________**********////////



// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         string s1= p;
//         string s2= s;
//         int  n= s1.size();
//         int m= s2.size();
//          vector<vector<bool>>dp(n+1 , vector<bool>(m+1,false));

//           // base case 1 (i<0 && j<0) return true;
//           // base case 2 (i>=0 && j<0) return false;

//             dp[0][0] = true;
//            for (int j = 1; j <= m; j++) {
//                dp[0][j] = false;
//            }
//           // base case 3 (i<0 && j>=0)

//           for(int i=1;i<=n;i++){
//             bool flag=true;
//              for(int k=1;k<=i;k++){
//                 if(s1[k-1]!='*'){
//                     flag = false;
//                     break;
//                 }
//             }
//              dp[i][0] = flag;
//           }

//         for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?') {
//                 dp[i][j] = dp[i - 1][j - 1];
//             } else {
//                 if (s1[i - 1] == '*') {
//                     dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//                 } else {
//                     dp[i][j] = false;
//                 }
//             }
//         }
//     }

//     // The value at dp[n][m] contains whether S1 matches S2
//     return dp[n][m];
//     }

// };

///////////******______----------- MEMOIZation SOLUTION --------___________**********////////


// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int  n= s.size();
//         int m= p.size();
//         vector<vector<int>>dp(n+1 , vector<int>(m+1,-1));
//         return utilFunction(s,p,n-1,m-1,dp);
//     }
// private: 
//     bool utilFunction(string &s, string &p , int i , int j ,vector<vector<int>>&dp){
//         //base case
//         if(i<0 && j<0) return true;
//         if(i>=0 && j<0) return false;
//         if(i<0 && j>=0){
//             for(int k=0;k<=j;k++){
//                 if(p[k]!='*') return false;
//             }
//             return true;
//         }

//         // dp
//         if(dp[i][j]!=-1) return dp[i][j];
//         // code 
//         if(s[i]== p[j] || p[j]=='?')   return  dp[i][j]= utilFunction(s,p,i-1,j-1,dp);

//         if(p[j]=='*') return  dp[i][j]= (utilFunction(s,p,i-1,j,dp)|| utilFunction(s,p,i,j-1 ,dp));

//         return  dp[i][j]= false ; 
//     }
// };

///////////******______----------- RECURSIVE SOLUTION --------___________**********////////


// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int  n= s.size();
//         int m= p.size();

//         return utilFunction(s,p,n-1,m-1);
//     }
// private: 
//     bool utilFunction(string &s, string &p , int i , int j){
//         //base case
//         if(i<0 && j<0) return true;
//         if(i>=0 && j<0) return false;
//         if(i<0 && j>=0){
//             for(int k=0;k<=j;k++){
//                 if(p[k]!='*') return false;
//             }
//             return true;
//         }

//         // code 
//         if(s[i]== p[j] || p[j]=='?')   return utilFunction(s,p,i-1,j-1);

//         if(p[j]=='*') return (utilFunction(s,p,i-1,j)|| utilFunction(s,p,i,j-1));

//         return false ; 
//     }
// };