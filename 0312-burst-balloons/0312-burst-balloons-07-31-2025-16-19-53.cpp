class Solution {
public:
    vector<vector<int>>dp;
    int  helper(vector<int>& nums,int i, int j ){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int steps = nums[k]*nums[i-1]*nums[j+1] + helper(nums, i, k-1) + helper(nums ,k+1,j);
            maxi= max(maxi, steps);
        }
        // answer+= maxi;
        return dp[i][j]= maxi;
    }
    int maxCoins(vector<int>& nums) {
        int  n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        dp.assign(n+1, vector<int>(n+2,-1));
        return  helper(nums, 1 ,n);
        

    }
};