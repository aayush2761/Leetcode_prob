class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> count(n, 0);
        int maxi=0;
        for (int i = 0; i < n; i++) {
            dp[i]=1;
            count[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        count[i] += count[j];
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }

        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                result += count[i];
            }
        }

        return result;
    }
};
