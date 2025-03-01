class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        // res.insert({});
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            for(int j=i;j<nums.size();j++){
                temp.push_back(nums[j]);
                res.insert(temp);
            }
        }
        // return res;
        vector<vector<int>> ans;
        ans.push_back({});
        for(auto it : res) ans.push_back(it);
        return ans;
    }
};