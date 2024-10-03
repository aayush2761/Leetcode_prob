class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if(total % p == 0) return 0;
        
        int rem = total % p;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        long long prefSum = 0;
        int mini = nums.size();
        
        for(int i = 0; i < nums.size(); ++i) {
            prefSum += nums[i];
            int curr = prefSum % p;
            int target = (curr - rem + p) % p;

            if(mp.find(target) != mp.end()) {
                mini = min(mini, i - mp[target]);
            }
            mp[curr] = i;
        }
        
        return mini == nums.size() ? -1 : mini;
    }
};
