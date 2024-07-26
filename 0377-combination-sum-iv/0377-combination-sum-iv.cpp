// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int>candidates(nums.begin(),nums.end());
//         vector<int> vec;
//          int res;

//         combinationSumHelper(0,candidates,target,0,vec,res);
//         return res;
//     }
// private:
//     void combinationSumHelper(int i, vector<int>& candidates, int target, int sum, vector<int>& vec, int& res) {
//         // base case
//         if (sum == target ) {
//            vector<int>temp(vec.begin(),vec.end());
//            res+=1;
//            next_permutation(vec.begin(),vec.end());
//            while(vec!=temp){
//             res+=1;
//             next_permutation(vec.begin(),vec.end());
//            }
//            return;
//         }
//         if (i == candidates.size()) {
//             return;
//         }

//         // pick
//         // only once
        
//         // if (sum + candidates[i] <= target) {  // correct sum update
//         //     vec.push_back(candidates[i]);
//         //     combinationSumHelper(i + 1, candidates, target, sum + candidates[i], vec, res,k);  // correct sum update
//         //     vec.pop_back();
//         // }

//          if (sum + candidates[i] <= target) {  // correct sum update
//             vec.push_back(candidates[i]);
//             combinationSumHelper(i + 1, candidates, target, sum + candidates[i], vec, res);  // correct sum update
//             vec.pop_back();
//         }

//         // not pick
//         // skip duplicates
//         // while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
//         //     i++;
//         // }
//         combinationSumHelper(i + 1, candidates, target, sum, vec, res);
//     }
// };


// // class Solution {
// // public:
// //     int combinationSum4(vector<int>& nums, int target) {
// //         // Sort the nums to handle duplicates and ease the logic
// //         // sort(nums.begin(), nums.end());
        
// //         // Initialize res to 0
// //         int res = 0;
        
// //         // Start the helper function
// //         vector<int> vec;
// //         combinationSumHelper(0, nums, target, 0, vec, res);
        
// //         // Return the result
// //         return res;
// //     }

// // private:
// //     int combinationSumHelper(int i, vector<int>& candidates, int target, int sum) {
// //         // Base case: if the sum equals the target, increment the result count
// //         if (sum == target) {
// //             // res++;
// //             return 1;
// //         }

// //         // If the sum exceeds the target or the index is out of bounds, return
// //         if (sum > target || i == candidates.size()) {
// //             return;
// //         }

// //         // // Pick the current candidate
// //         // vec.push_back(candidates[i]);
// //         // combinationSumHelper(i, candidates, target, sum + candidates[i], vec, res);
// //         // vec.pop_back();

// //         // // Not pick the current candidate and move to the next distinct candidate
// //         // // while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
// //         // //     i++;
// //         // // }
// //         // combinationSumHelper(i + 1, candidates, target, sum, vec, res);

// //          int res=0;
// //        for(int i=0;i<n;i++)
// //        {  if(sum+nums[i]<=target)
// //            res+=helper(nums,target,n,sum+nums[i]);
// //        }

// //        return res;
// //     }
// // };



class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1); 
        dp[0] = 1;  
        return combinationSumHelper(nums, target, dp);
    }

private:
    int combinationSumHelper(vector<int>& nums, int target, vector<int>& dp) {
        if (dp[target] != -1) {
            return dp[target];
        }

        int res = 0;
        for (int num : nums) {
            if (target >= num) {
                res += combinationSumHelper(nums, target - num, dp);
            }
        }

        dp[target] = res;
        return res;
    }
};

