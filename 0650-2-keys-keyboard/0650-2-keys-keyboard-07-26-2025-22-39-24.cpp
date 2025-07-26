class Solution {
public:
    int minSteps(int n) {
        // dp[i] -> minimum ops required to achieve the i 
        // 1 -> 0 
        // 2 -> 1 copy + 1 paste = 2
        vector<int>dp(n+1,INT_MAX);
        dp[1]=0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>0;j--){
                // copy whole j-1 items and paste x time 
                if(i%j==0){
                    dp[i]= min(dp[i], dp[j] +1+  (i-j)/j);
                }
            }
        }
        return dp[n];
    }
};