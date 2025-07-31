class Solution {
public:
vector<vector<int>>dp;
    int count(int i, int j , vector<int>& nums){
        unordered_map<int,int> mp;
        for(int k=i;k<=j;k++) mp[nums[k]]++;
        int ans=0;
        for(auto &it : mp){
            if(it.second > 1) ans += it.second;
        }
        return ans;
    }

    long long solve(vector<int>& nums, int subs, int i, int j,vector<vector<long long>> &costs){
        // if(i > j) return 0;
        if(i > j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long steps = 1e12;
        for(int k=i; k<=j; k++){
            long long x =costs[i][k] + solve(nums, subs, k+1, j, costs);
            steps = min(steps, x);
        }
        return dp[i][j]= steps;
    }

    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        dp.assign(n, vector<int>(n,-1));
         vector<vector<long long>> cost(n , vector<long long>(n, 0));
        
        // PreCompute Cost for every Subarray
        
        for(int i=0; i < n; i++){
            unordered_map<int,int> mp;
            long long cnt = 0;
            
            for(int j= i; j < n; j++){
                
                mp[nums[j]]++;
                
                // If the number is Occuring only 1 time then it will be removed in the trimmed(subarray)
                
                if(mp[nums[j]] > 1){
                    if(mp[nums[j]] == 2) cnt += 2;
                    
                    else cnt++;
                    
                }
                
                // cnt is the total count of numbers that is that appears more than ones in this subarray 
                cost[i][j] = cnt + k;
            }
        }
        return (int)solve(nums, k, 0, (int)nums.size()-1, cost);
    }
};
