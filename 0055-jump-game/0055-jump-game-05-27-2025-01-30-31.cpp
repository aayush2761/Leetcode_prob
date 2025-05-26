class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp[i] -> states that ith index possible or not 
        int n= nums.size();
        vector<bool>dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            int x = nums[i];
            for(int j=i+1;j<=i+x && j<n;j++ ){
                if(dp[j]==true){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};