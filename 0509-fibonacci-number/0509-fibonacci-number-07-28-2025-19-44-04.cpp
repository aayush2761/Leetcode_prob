class Solution {
public:
    vector<int>dp;
    int fib(int n) {
        dp.assign(n+1,-1);
        dp[0]=0, dp[1]=1;
       for(int i=2;i<=n;i++) dp[i]= dp[i-1] + dp[i-2];
       return dp[n];
    }
};