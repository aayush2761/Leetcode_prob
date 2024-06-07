// // space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
          vector<vector<int>>after(2,vector<int>(3,0));
          vector<vector<int>>curr(2,vector<int>(3,0));
        // BASE CASES

        // for cap 
        // for(int i=0;i<n;i++){
        //     for(int buy=0;buy<=1;buy++){
        //         dp[i][buy][0]=0;
        //     }
        // }

        // // for index
        // for(int buy=0;buy<=1;buy++){
        //     for(int cap=0;cap<=2;cap++){
        //         dp[0][buy][cap]=0;
        //     }
        // }

// changing parmeter functions

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
             for(int cap=1;cap<=2;cap++){
                
                if(buy==1){
           curr[buy][cap]= max (
                -prices[i] +after[0][cap] ,   // buy
                0 +  after[1][cap]  // not buy
            );
        }
        // sell case
        else {
            curr[buy][cap]= max(
                prices[i] +  after[1][cap-1] , // selling done 
                0 +   after[0][cap]    // still selling not done
            );
        }
      


             }

         
            }
            after=curr;
        }
        return after[1][2];
    }
};



// tabulation 

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//          vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2,vector<int>(3,0)));
//         // BASE CASES

//         // for cap 
//         // for(int i=0;i<n;i++){
//         //     for(int buy=0;buy<=1;buy++){
//         //         dp[i][buy][0]=0;
//         //     }
//         // }

//         // // for index
//         // for(int buy=0;buy<=1;buy++){
//         //     for(int cap=0;cap<=2;cap++){
//         //         dp[0][buy][cap]=0;
//         //     }
//         // }

// // changing parmeter functions

//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//              for(int cap=1;cap<=2;cap++){
                
//                 if(buy==1){
//            dp[i][buy][cap]= max (
//                 -prices[i] +dp[i+1][0][cap] ,   // buy
//                 0 +  dp[i+1][1][cap]  // not buy
//             );
//         }
//         // sell case
//         else {
//             dp[i][buy][cap]= max(
//                 prices[i] +  dp[i+1][1][cap-1] , // selling done 
//                 0 +   dp[i+1][0][cap]    // still selling not done
//             );
//         }
      


//              }

         
//             }
//         }
//         return dp[0][1][2];
//     }
// };




// memoization solution *******  3D DP   -+********

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int index=0;
//         int profit=0;
//         int n = prices.size();
//         // 3D dp
//         vector<vector<vector<int>>>dp(n , vector<vector<int>>(2,vector<int>(3,-1)));
//         return utilFunction(index, 1, profit , prices , dp , 2);
//     }
// private:
//     int utilFunction(int index, bool buy , int &profit, vector<int>& prices, vector<vector<vector<int>>>&dp , int cap){
//         if(cap==0) return 0;
//         if( index== prices.size()) return 0;

//         if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
//         // buy case 
//         if(buy){
//             profit= max (
//                 -prices[index] + utilFunction(index+1 , 0 , profit , prices , dp , cap) ,   // buy
//                 0 +  utilFunction(index+1 , 1 , profit , prices, dp , cap)  // not buy
//             );
//         }
//         // sell case
//         else {
//             profit= max(
//                 prices[index] +  utilFunction(index+1 , 1 , profit , prices , dp , cap-1) , // selling done 
//                 0 +   utilFunction(index+1 , 0 , profit , prices , dp , cap)    // still selling not done
//             );
//         }
//         return  dp[index][buy][cap]=profit;
//     }
// };



// RECURSIVE SOLLUTION  just like knap sack


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int index=0;
//         int profit=0;
//         int cap=2;
//         return utilFunction(index, 1, profit , prices , cap);
//     }
// private:
//     int utilFunction(int index, bool buy , int &profit, vector<int>& prices, int cap){
//         if(cap==0) return 0;
//         if( index== prices.size()) return 0;

//         // buy case 
//         if(buy){
//             profit= max (
//                 -prices[index] + utilFunction(index+1 , 0 , profit , prices ,cap) ,   // buy
//                 0 +  utilFunction(index+1 , 1 , profit , prices, cap)  // not buy
//             );
//         }
//         // sell case
//         else {
//             profit= max(
//                 prices[index] +  utilFunction(index+1 , 1 , profit , prices, cap-1) , // selling done 
//                 0 +   utilFunction(index+1 , 0 , profit , prices , cap)    // still selling not done
//             );
//         }
//         return profit;
//     }
// };