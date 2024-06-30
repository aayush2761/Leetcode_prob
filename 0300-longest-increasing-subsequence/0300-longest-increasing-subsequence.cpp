class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int ind=0;
        int n= nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1 , 0));

        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                
                 
                  int notTake= dp[ind+1][prev+1];
                  int take=0;
                  if(prev==-1 || nums[ind]>nums[prev]){
                      take= 1+ dp[ind+1][ind+1];
                  }

                 dp[ind][prev+1]= max(take, notTake);
            }
        }
        return dp[0][0];
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