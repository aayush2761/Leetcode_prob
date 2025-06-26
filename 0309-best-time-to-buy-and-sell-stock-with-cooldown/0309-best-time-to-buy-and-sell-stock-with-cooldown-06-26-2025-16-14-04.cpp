class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // cool down is of one day -> consider this also as variable -> cooldown or notcooldown 

        
         // 1-> owning of the stock 
         // 1-> in the cool down period so cannot buy this period 
        // dp[i][1]-> this represent the maximum profit till i and i own a stock on day i  
        // dp[i][0] -> maximum profit till i and i donot own the stock 
        int n = prices.size();
        if(n==1) return 0;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(2,-1)));
        // final subproblem 
        dp[0][1][0] = -prices[0];
        dp[0][0][0] = 0;
        dp[1][1][0] = max(-prices[0], -prices[1]);
        dp[1][0][0] = max(0, prices[1] - prices[0]);


        for(int i=2;i<prices.size();i++){
           // im on not cool down and buying a stock
           dp[i][1][0] = max(-prices[i]+ dp[i-2][0][0], dp[i-1][1][0]); // consider cool down here bhai 
           // i m on not cool down and selling the stock 
           dp[i][0][0] = max(prices[i]+ dp[i-1][1][0], dp[i-1][0][0]);

        }
        return dp[n-1][0][0]; // max profit with no stock in the hand :))
    }
};