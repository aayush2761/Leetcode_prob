class Solution {
public:
    bool solve(vector<int>& nums,vector<bool>vis,int k, int ind, int reqSum , int currSum){
        if (k == 0) return true; 
        if (currSum == reqSum)
            return solve(nums, vis, k - 1, 0, reqSum, 0); 
        for (int i = ind; i < nums.size(); i++) {
            if (!vis[i] && currSum + nums[i] <= reqSum) {
                vis[i] = true;
                if (solve(nums, vis, k, i + 1, reqSum, currSum + nums[i])) 
                    return true;
                vis[i] = false; 
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum%k!=0) return 0;
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        if(nums[0]>(totalSum/k)) return 0;
        vector<bool>vis(n,false);
        int ind=0;
        int currSum=0, reqSum = totalSum/k;
        return solve(nums,vis,k,ind, reqSum, currSum);


    }
};









// dp[i] indicates whether array of length 
// i can partitioned into k subsets of equal sum. 
// Using this technique, the last index of this dp array
// will tell whether the whole array can be partitioned into k subsets of equal sum