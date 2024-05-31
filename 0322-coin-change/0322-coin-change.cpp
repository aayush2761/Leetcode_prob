///////*********-------______ SPACE OPTIMIZATIION SOLUTION_________-------**********////////

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0 ) return 0;
        int n = coins.size();
        // dp[n][target+1]

        vector<int>prev(amount+1, 0);

        for(int i= 0;i<=amount;i++) {
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]= 1e9;
        }
        for(int i=1;i<n;i++){
            vector<int>curr(amount+1,0);
            for(int target= 0; target<=amount; target++){
                  int notTake= 0+ prev[target];
                  int take= INT_MAX;
                  if(coins[i]<=target) take= 1+curr[target- coins[i]];

                 curr[target]= min(take, notTake);
            }
            prev=curr;
        }
        int res=  prev[amount];
        if(res>= 1e9) return -1;
        return res;
    }
};



// -----------------------------------------------------------------------------------------//



///////*********-------______ TABULATION SOLUTION_________-------**********////////

// class Solution {
// public:
    
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount ==0 ) return 0;
//         int n = coins.size();
//         // dp[n][target+1]

//         vector<vector<int>>dp(n, vector<int>(amount+1, 0));

//         for(int i= 0;i<=amount;i++) {
//             if(i%coins[0]==0) dp[0][i]=i/coins[0];
//             else dp[0][i]= 1e9;
//         }
//         for(int i=1;i<n;i++){
//             for(int target= 0; target<=amount; target++){
//                   int notTake= 0+ dp[i-1][target];
//                   int take= INT_MAX;
//                   if(coins[i]<=target) take= 1+dp[i][target- coins[i]];

//                   dp[i][target]= min(take, notTake);
//             }
//         }
//         int res=  dp[n-1][amount];
//         if(res>= 1e9) return -1;
//         return res;
//     }
// };



// -----------------------------------------------------------------------------------------//



///////*********-------______ MEMOIZATION SOLUTION_________-------**********////////


// class Solution {
// public:
//     int utlFunction(int index, int target,vector<int>& coins,vector<vector<int>>&dp){
//         // base case 
//         if(index==0){
//             if(target%coins[index]==0 ) return  target/coins[index];
//             else return 1e8;
//         }
//         // code 
//         if(dp[index][target]!=-1) return dp[index][target];
//         int notTake= utlFunction(index-1, target, coins, dp);
//         int take= INT_MAX;
//         if(target>=coins[index]) take= 1+ utlFunction(index, (target-coins[index]), coins,dp);

//         return dp[index][target]= min(notTake, take);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount ==0 ) return 0;
//         int n = coins.size();
//         vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
//         int res= utlFunction(n-1, amount, coins,dp);
//         if(res==1e8) return -1;
//         return res;
//     }
// };

// -----------------------------------------------------------------------------------------//


///////*********-------______ RECURSIVE SOLUTION_________-------**********////////



// class Solution {
// public:
//     int utlFunction(int index, int target,vector<int>& coins){
//         // base case 
//         if(index==0){
//             if(target%coins[index]==0 ) return target/coins[index];
//             else return 1e8;
//         }
//         // code 
//         int notTake= utlFunction(index-1, target, coins);
//         int take= INT_MAX;
//         if(target>=coins[index]) take= 1+ utlFunction(index, (target-coins[index]), coins);

//         return min(notTake, take);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount ==0 ) return 0;
//         int n = coins.size();
//         //vector<vector<int>>dp(n, vector<int>(target+1, -1));
//         int res= utlFunction(n-1, amount, coins);
//         if(res==1e8) return -1;
//         return res;
//     }
// };