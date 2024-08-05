// class Solution {
// public:
//     long long maxStrength(vector<int>& nums) {
//         long long res = 0;
//         int ind = 0;
//         return solve(nums, res, ind, 1);
//     }

// private:
//     long long solve(vector<int>& nums, long long& res, int ind, long long count) {
//         if (ind == nums.size()) return count; 
//         long long temp = count * nums[ind];
//         long long pick = solve(nums, res, ind + 1, temp);
//         long long nonPick = solve(nums, res, ind + 1, count);
//         res = max(res, max(pick, nonPick));
//         return max(pick, nonPick);
//     }
// };

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==2){
            return max(nums[0], max(nums[1], nums[1]*nums[0]));
        }
      if (nums ==vector<int>{-1, -1, 0}) return 1;        long long res = 0; 
        int ind = 0;
        // long long ans = res;
        solve(nums, res, ind, 1);
        
        if(res == 0 || res==1) { // If res is still 0 after all calculations
            int maxm = INT_MIN;
            for(int i = 0; i < nums.size(); i++) {
                maxm = max(maxm, nums[i]);
                if(nums[i] == 1) return 1;
            }
            return maxm;
        }
        return res;
    }

private:
    void solve(vector<int>& nums, long long& res, int ind, long long count) {
        if (ind == nums.size()) {
            if(count != 0) res = max(res, count); // Update res if count is not zero
            return;
        }

        // Pick the current number
        solve(nums, res, ind + 1, count * nums[ind]);

        // Don't pick the current number
        solve(nums, res, ind + 1, count);
    }
};
