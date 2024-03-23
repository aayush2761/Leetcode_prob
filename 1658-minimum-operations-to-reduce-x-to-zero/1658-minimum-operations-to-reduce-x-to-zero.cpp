class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for (int i = 0; i < nums.size(); i++)
            target += nums[i];
     
        if (target == 0) return nums.size();
        if (target < 0) return -1;
        
        int i = 0, j = 0;
        int sum = 0, maxLen = -1;
        while (i < nums.size()) {
            sum += nums[i];  
            if (sum == target) {
                maxLen = max(maxLen, i - j + 1);
            }
            while (sum > target) {
                sum -= nums[j++];
                if (sum == target) {
                    maxLen = max(maxLen, i - j + 1);
                }
            }
            i++;
        }
        return (maxLen == -1) ? -1 : nums.size() - maxLen;
    }
};
