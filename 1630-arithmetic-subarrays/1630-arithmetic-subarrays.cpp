class Solution {
public:
    bool check(int left, int right, vector<int>& nums) {
        vector<int> sub(nums.begin() + left, nums.begin() + right + 1);
        sort(sub.begin(), sub.end());
        int diff = sub[1] - sub[0];
        for (int i = 1; i < sub.size(); i++) {
            if (sub[i] - sub[i - 1] != diff) return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = check(l[i], r[i], nums);
        }
        return res;
    }
};
