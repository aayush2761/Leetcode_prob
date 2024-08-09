class Solution {
public:
     int mod = 1e9 + 7;

    int solve(vector<int>& nums, int mask, int prev, int count, vector<vector<int>>& dp) {
        if (count == nums.size()) {
            return 1;
        }
        if (dp[mask][prev] != -1) return dp[mask][prev];

        long long ways = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (mask & (1 << i)) continue;  // already visited

            if (mask != 0 && nums[i] % nums[prev] != 0 && nums[prev] % nums[i] != 0) continue;

            ways = (ways + solve(nums, mask | (1 << i), i, count + 1, dp)) % mod;
        }

        return dp[mask][prev] = ways;
    }

    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp((1 << n), vector<int>(n, -1));  // dp[mask][prev]

        int mask = 0;  // no element is selected
        int prev = 0;  // last taken index
        int count = 0;  // count of number of elements taken 

        return solve(nums, mask, prev, count, dp);
    }
};
    
// 529 cases are passed out of 600++
//  this is the recursive solution 
// tc approx (n!*n)



// class Solution {
// public:
//     int mod = 1e9 + 7;

//     void solve(vector<int>& nums, int &res, vector<int>& temp, vector<bool>& freq, int prev) {
//         if (temp.size() == nums.size()) {
//             res += 1;
//             return;
//         }

//         for (int i = 0; i < nums.size(); i++) {
//             if (!freq[i]) {
//                 if (prev != -1 && nums[i] % nums[prev] != 0 && nums[prev] % nums[i] != 0) continue;

//                 freq[i] = true;
//                 temp.push_back(nums[i]);

//                 solve(nums, res, temp, freq, i);

//                 temp.pop_back();
//                 freq[i] = false;
//             }
//         }
//     }

//     int specialPerm(vector<int>& nums) {
//         int res = 0;
//         vector<int> temp;
//         vector<bool> freq(nums.size(), false);
//         solve(nums, res, temp, freq, -1);
//         return res % mod;
//     }
// };
