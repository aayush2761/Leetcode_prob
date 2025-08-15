class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end() ){
                if(target-nums[i]== nums[i] ){
                  if(mp[nums[i]].size() < 2) continue;
                    return {mp[nums[i]][0], mp[nums[i]][1]};
                }
                 return {i, mp[target-nums[i]].back()};
            }
        }
        return {};
    }
};