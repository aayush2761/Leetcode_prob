class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 1; // Start count at 1 for the starting element
                int k = i; // Start k from i
                int diff = nums[j] - nums[i];
                int prev = nums[j];
                
                while (k >= 0) {
                    if (prev - nums[k] == diff) {
                        count++;
                        prev = nums[k];
                    }
                    k--;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int res = 0; 
//         solve(nums, 0, -1, -1, res);
//         return res; 
//     }

//     int solve(vector<int>& nums, int ind, int prev, int diff, int &res) {
//         if (ind == nums.size()) {
//             return 0;
//         }
//         int notPick = solve(nums, ind + 1, prev, diff, res);
//         int pick = 0;
//         if (prev == -1) {
          
//             pick = 1 + solve(nums, ind + 1, ind, diff, res);
//         } else {
//             int currentDiff = nums[ind] - nums[prev];
//             if (diff == -1 || currentDiff == diff) {
               
//                 pick = 1 + solve(nums, ind + 1, ind, currentDiff, res);
//             }
//         }
//         res = max(res, max(pick, notPick));
//         return max(pick, notPick);
//     }
// };
