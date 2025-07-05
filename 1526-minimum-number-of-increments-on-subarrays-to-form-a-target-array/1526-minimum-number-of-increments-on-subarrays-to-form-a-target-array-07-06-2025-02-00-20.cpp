class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // dp[i] -> sttaes that maximum increment required from o to ith index 
        int n= target.size();
        vector<int>dp(n);
        dp[0]= target[0];
         for(int i=1;i<n;i++){
            // not pick case type
            if(target[i]<= target[i-1]) dp[i]= dp[i-1];
            else dp[i] = dp[i-1]+ target[i]-target[i-1]; // pick case with the extra needed stepup
         }
         return dp[n-1];
    }
};