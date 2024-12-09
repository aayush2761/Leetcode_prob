class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> pre(nums.size(),0);
        vector<bool> ans;
        for(int i=1;i<nums.size();i++)
            pre[i] = pre[i-1] + (nums[i]%2 == nums[i-1]%2);
        for(auto& q:queries)
            ans.push_back(pre[q[1]] == pre[q[0]]);
        return ans;
    }
};