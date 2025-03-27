class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return -1;
        unordered_map<int, int> mp;
        for (auto &it : nums) mp[it]++;

        int mostFrequent = -1, count = 0;
        for (auto &it : mp) {
            if (it.second > count) {
                count = it.second;
                mostFrequent = it.first;
            }
        }

        
        int forwardCount = 0;
        vector<int> forward(n, 0);

        for (int i = 0; i < n; i++) {
            if (mostFrequent == nums[i]) {
                forwardCount++;
            }
            forward[i] = forwardCount; 
        }

        int backwardCount = 0;
        int res=INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (mostFrequent == nums[i]) {
                backwardCount++;
            }
            if (2 * forward[i] > i + 1 && 2 * backwardCount > n - i) {
                res=min(res,i);
            }
        }
        if(res<n/2-1) return -1;
        return res==INT_MAX? -1 : res;
    }
};
