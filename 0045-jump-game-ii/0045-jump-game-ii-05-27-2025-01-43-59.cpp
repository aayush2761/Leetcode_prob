class Solution {
public:
    int jump(vector<int>& nums) {
        // dp[i]-> minimum jumps required to reach from ith index to nth index 
        int n= nums.size();
        vector<int>dp(n,1e9);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j= 1;j<=nums[i];j++){
                if(i+j<n){
                    dp[i]=min(dp[i],1+dp[i+j]);
                    // cout<<"Hello"<<endl;
                }
            }
        }
        return dp[0];
    }
};