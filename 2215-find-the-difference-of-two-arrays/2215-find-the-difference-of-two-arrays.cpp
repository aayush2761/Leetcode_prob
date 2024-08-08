class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        
        // Count occurrences in nums1
        for (auto i : nums1) mp1[i]++;
        
        // Count occurrences in nums2
        for (auto i : nums2) mp2[i]++;
        
        vector<int> res1; 
        vector<int> res2;

        // // Elements in nums1 but not in nums2
        // for (auto& i : mp1) {
        //     if (mp2.find(i.first) == mp2.end()) {
        //         int t = i.second;
        //         while (t--) {
        //             res1.push_back(i.first);
        //         }
        //     }
        // }
        
        // // Elements in nums2 but not in nums1
        // for (auto& i : mp2) {
        //     if (mp1.find(i.first) == mp1.end()) {
        //         int t = i.second;
        //         while (t--) {
        //             res2.push_back(i.first);
        //         }
        //     }
        // }
         for (auto& i : mp1) {
            if (mp2.find(i.first) == mp2.end()) {
                res1.push_back(i.first);
            }
        } 

        for (auto& i : mp2) {
            if (mp1.find(i.first) == mp1.end()) {
                res2.push_back(i.first);
            }
        }
        
        return {res1, res2};
    }
};
