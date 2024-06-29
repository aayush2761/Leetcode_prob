class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        long long ans = INT_MIN;
        long long sum = 0;

        while (i < nums.size()) {
            sum += nums[i];
            if (abs(nums[i] - nums[j]) == k) {
                ans = max(ans, sum);
                j=i;
                sum=nums[j];
            } 
            i++;
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};