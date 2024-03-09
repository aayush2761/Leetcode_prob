class Solution {
public:
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set(nums1.begin(), nums1.end());
        
        for(auto num : nums2) {
            if(set.find(num) != set.end()) {
                return num;
            }
        }
        
        return -1;
    }
};