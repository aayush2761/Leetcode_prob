class Solution {
public:
void solve(vector<int>& nums, int idx,set<vector<int>>&res,vector<int>temp){
        if(idx==nums.size()){
            res.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1,res,temp);
        temp.pop_back();
        solve(nums,idx+1,res,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>res;
         set<vector<int>>st;
        vector<int>temp;
        int start=0;
        solve(nums,0,st,temp);
        for(auto &it : st) res.push_back(it);
        return res;
    }
};
