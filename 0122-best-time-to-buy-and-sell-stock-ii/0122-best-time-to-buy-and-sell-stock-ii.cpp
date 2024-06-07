// space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int index=0;
        int profit=0;
        int n = prices.size();
       // vector<vector<int>>dp(n+1 , vector<int>(2,-1));
       vector<int>ahead(2,0) , curr(2,0);
        ahead[0]=ahead[1]=0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                long profit=0;
                // copy the recurences 
                 // buy case 
        if(buy){
            profit= max (
                -prices[i] + ahead[0] ,   // buy
                0 +  ahead[1]  // not buy
            );
        }
        // sell case
        else {
            profit= max(
                prices[i] +  ahead[1] , // selling done 
                0 +  ahead[0]    // still selling not done
            );
        }

         curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }
};



// tabulation 

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int index=0;
//         int profit=0;
//         int n = prices.size();
//         vector<vector<int>>dp(n+1 , vector<int>(2,-1));
//         dp[n][0]=dp[n][1]=0;

//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//                 long profit=0;
//                 // copy the recurences 
//                  // buy case 
//         if(buy){
//             profit= max (
//                 -prices[i] + dp[i+1][0] ,   // buy
//                 0 +  dp[i+1][1]  // not buy
//             );
//         }
//         // sell case
//         else {
//             profit= max(
//                 prices[i] +  dp[i+1][1] , // selling done 
//                 0 +   dp[i+1][0]    // still selling not done
//             );
//         }

//          dp[i][buy]=profit;
//             }
//         }
//         return dp[0][1];
//     }
// };




// memoization solution

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int index=0;
//         int profit=0;
//         int n = prices.size();
//         vector<vector<int>>dp(n , vector<int>(2,-1));
//         return utilFunction(index, 1, profit , prices , dp);
//     }
// private:
//     int utilFunction(int index, bool buy , int &profit, vector<int>& prices,vector<vector<int>>&dp){
//         if( index== prices.size()) return 0;

//         if(dp[index][buy]!=-1) return dp[index][buy];
//         // buy case 
//         if(buy){
//             profit= max (
//                 -prices[index] + utilFunction(index+1 , 0 , profit , prices , dp) ,   // buy
//                 0 +  utilFunction(index+1 , 1 , profit , prices, dp)  // not buy
//             );
//         }
//         // sell case
//         else {
//             profit= max(
//                 prices[index] +  utilFunction(index+1 , 1 , profit , prices , dp) , // selling done 
//                 0 +   utilFunction(index+1 , 0 , profit , prices , dp)    // still selling not done
//             );
//         }
//         return  dp[index][buy]=profit;
//     }
// };



// RECURSIVE SOLLUTION 


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int index=0;
//         int profit=0;
//         return utilFunction(index, 1, profit , prices);
//     }
// private:
//     int utilFunction(int index, bool buy , int &profit, vector<int>& prices){
//         if( index== prices.size()) return 0;

//         // buy case 
//         if(buy){
//             profit= max (
//                 -prices[index] + utilFunction(index+1 , 0 , profit , prices) ,   // buy
//                 0 +  utilFunction(index+1 , 1 , profit , prices)  // not buy
//             );
//         }
//         // sell case
//         else {
//             profit= max(
//                 prices[index] +  utilFunction(index+1 , 1 , profit , prices) , // selling done 
//                 0 +   utilFunction(index+1 , 0 , profit , prices)    // still selling not done
//             );
//         }
//         return profit;
//     }
// };