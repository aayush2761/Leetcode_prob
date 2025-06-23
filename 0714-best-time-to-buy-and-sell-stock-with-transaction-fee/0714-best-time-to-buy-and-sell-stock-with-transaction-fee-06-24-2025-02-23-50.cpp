class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 1-> owning of the stock 
        // dp[i][1]-> this represent the maximum profit till i and i own a stock on day i  
        // dp[i][0] -> maximum profit till i and i donot own the stock 
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        // final subproblem 
        dp[0][1]= -(prices[0]+ fee);// buying 
        dp[0][0]=0; // not  buying 
        for(int i=1;i<prices.size();i++){
            // i do not own the stock -> what i did -> either i sold it or do not do any thing  
            dp[i][0]= max(dp[i-1][0],prices[i]+ dp[i-1][1]);
             // already i own a stock ->what i did today -> either i bought a stock or just hold prev 
            dp[i][1] = max(dp[i-1][1] ,-(fee+prices [i])+ dp[i-1][0]);
        }
        return dp[n-1][0]; // max profit with no stock in the hand :))
    }
};