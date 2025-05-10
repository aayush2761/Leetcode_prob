class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int  n = nums.size();
        if(target==0 ){
            if(nums[0]== nums[n-1]) return 1;
            return -1;
        }
        vector<int>dp(n,-1);
        // dp[i]--> maximum number of steps needed to reach the nth index from the ith index !!
        dp[n-1]=0;   // that how you handle subproblmmme!!!
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int x = nums[j]-nums[i];
                if(x>= -1*target && x<=target && dp[j]!=-1)dp[i]=max(dp[i], 1+dp[j]);
            }
        }
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return dp[0]==0 ? -1 : dp[0];
    }
};