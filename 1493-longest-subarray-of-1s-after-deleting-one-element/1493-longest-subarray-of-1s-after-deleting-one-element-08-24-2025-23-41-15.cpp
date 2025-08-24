class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int temp = 0;
        int i = 0, j = 0;

        while (i < n) {
            if (nums[i] == 0) temp += 1;
            
            while (temp > 1) {
                if (nums[j] == 0) temp -= 1;
                j++;
            }
            
            res = max(res, i - j);
            i++;
        }
        
        // If all elements are 1, then we need to remove one element, so result is n-1
        return res == n ? res - 1 : res;
    }
};
