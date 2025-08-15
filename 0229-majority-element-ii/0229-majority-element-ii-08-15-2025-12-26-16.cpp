class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) j++;
            if (j - i > n / 3) res.push_back(nums[i]);
            i = j;
        }
        return res;
    }
};
