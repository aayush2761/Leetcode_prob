class Solution {
public:
    int check(vector<int>& nums, int left) {
        int res = (nums.size() * (nums.size() + 1)) / 2; 
        vector<int> vec;
        int i = 0, j = 0, n = nums.size();
        while (i < n) {
            if (nums[i] >= left) {
                if (i != j) {
                    vec.push_back(i - j);
                }
                j = i + 1;
            }
            i++;
        }
        if (j < n) vec.push_back(n - j); 
        for (int v : vec) {
            res -= (v * (v + 1)) / 2; 
        }
        return res;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res= 0, i = 0, j = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] > right) {
                vector<int> temp(nums.begin() + j, nums.begin() + i);
                res += check(temp, left);
                j = i + 1;
            }
            i++;
        }
        if (j < n) { 
            vector<int> temp(nums.begin() + j, nums.end());
            res += check(temp, left);
        }
        return res;
    }
};
