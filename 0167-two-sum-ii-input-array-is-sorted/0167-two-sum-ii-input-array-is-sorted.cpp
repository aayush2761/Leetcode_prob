class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            int find = target - nums[i];
            auto index = [&]() -> vector<int> {
                int low = 0, high = nums.size() - 1;
                while(low <= high) {
                    int mid = low + (high - low) / 2;
                    if(nums[mid] == find && i != mid) return {i+1, mid+1};
                    else if (nums[mid] > find) high=mid-1;
                    else low=mid+1;
                }
                return {}; 
            };
            vector<int> res = index();
            if(!res.empty()) return res;
        }
        return {};
    }
};
