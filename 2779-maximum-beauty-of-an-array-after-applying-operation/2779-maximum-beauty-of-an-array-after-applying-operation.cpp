class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(200002, 0); // Adjust size to cover large bounds

        for (int i = 0; i < n; i++) {
            int left = max(0, nums[i] - k);  
            int right = nums[i] + k;       
            diff[left]++;
            diff[right + 1]--;
        }

        int res = INT_MIN, curr = 0;
        for (int i = 0; i < diff.size(); i++) {
            curr += diff[i];
            res = max(res, curr);
        }

        return res;
    }
};
