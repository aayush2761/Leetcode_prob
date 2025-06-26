class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        vector<vector<int>>dp(n, vector<int>(2,-1));
        // final subproblem 
        dp[0][1]= -(prices[0]);// buying 
        dp[0][0]=0; // not  buying 
        // dp[1][1]= -(prices[1]);
        // dp[1][0]= 0;
        for(int i=1;i<prices.size();i++){
            // i do not own the stock -> what i did -> either i sold it or do not do any thing  
            dp[i][0]= max(dp[i-1][0],prices[i]+ dp[i-1][1]);
             // already i own a stock ->what i did today -> either i bought a stock or just hold prev 
            dp[i][1] = max(dp[i-1][1] ,-(prices [i])+ dp[i-1][0]);
        }
        return dp[n-1][0]; // max profit with no stock in the hand :))
    }
};