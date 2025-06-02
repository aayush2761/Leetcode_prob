class Solution {
public:
    bool subsetWithTarget(int n , vector<int>&nums,int target){
        int k= target;
        vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (nums[0] <= k) {
        prev[nums[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (nums[ind] <= target) {
                taken = prev[target - nums[ind]];
            }

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }

        // Update 'prev' with the current row 'cur' for the next iteration
        prev = cur;
    }

    // The final result is stored in prev[k]
    return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        int n = nums.size();
        for(int i=0;i<n;i++) totalSum+=nums[i];
        if(totalSum%2) return false;
        int target= totalSum/2;
        return subsetWithTarget(n, nums, target);
    }
};