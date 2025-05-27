class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]-> longest increasing subsequence from the oth index 
        int n = nums.size();
        vector<int>dp(n,1);
        // dp[0]=1;
        for(int i=1;i<n;i++){
            // transition equation
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]= max(dp[i],1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};



/// memoization 
// int lengthOfLIS(vector<int>& nums) {
//         int prev=-1;
//         int ind=0;
//         int n= nums.size();
//         vector<vector<int>>dp(n,vector<int>(n+1 , -1));
//         return solve(nums,ind,prev , dp);
//     }
//     int solve(vector<int>& nums ,int ind , int prev ,  vector<vector<int>>&dp){
//         if(ind==nums.size()) return 0;

//         if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
//         int notTake= solve(nums, ind+1 , prev , dp);
//         int take=0;
//         if(prev==-1 || nums[ind]>nums[prev]){
//             take= 1+ solve(nums, ind+1 , ind , dp);
//         }

//         return dp[ind][prev+1]= max(take, notTake);
//     }