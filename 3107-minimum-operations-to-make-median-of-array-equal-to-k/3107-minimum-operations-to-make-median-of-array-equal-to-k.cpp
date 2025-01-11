class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        // 0 based indexing ---->>>
        long long res = 0;
        int n = nums.size();
        if (n == 1) return abs(nums[0] - k);
        sort(nums.begin(), nums.end());
        
        int index = n / 2; 
        cout<<index<<endl;
        if (nums[index] != k) {
            res += abs(nums[index] - k);
            nums[index] = k; 
        }
        int i = index;
        while (i > 0 && nums[i] < nums[i - 1]) {
            res += nums[i - 1] - nums[i];
            nums[i - 1] = nums[i];
            i--;
        }
        i = index;
        while (i < n - 1 && nums[i] > nums[i + 1]) {
            res += nums[i] - nums[i + 1];
            nums[i + 1] = nums[i];
            i++;
        }

        return res;
    }
};
