class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                if(abs(mp[nums[i]].back()- i)<=k) return 1;
            }
            mp[nums[i]].push_back(i);
        }
        return 0;
    }
};