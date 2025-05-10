class Solution {
public:
    int jump(vector<int>& nums) {
        // state ---- dp[i] -> maximum jump reuired to reach the nth index from ith index
        int n= nums.size();
        vector<int>dp(n,10001);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                if(i+j<n)dp[i]=min(dp[i], 1+ dp[i+j]);
            }
        }
        //  for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return dp[0];
    }
};