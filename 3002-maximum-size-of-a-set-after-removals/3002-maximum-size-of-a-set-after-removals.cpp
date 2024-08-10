// class Solution {
// public:
//     int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
//         // return 0;
//         map<int, int> mp1;
//         for (auto i : nums1) mp1[i]++;
//         map<int, int> mp2;
//         for (auto i : nums2) mp2[i]++;
        
//         int n1 = nums1.size() / 2;
//         int n2 = nums2.size() / 2;
//         unordered_set<int> st;

//         while (n1 > 0) {
//             for (auto it = mp1.begin(); it != mp1.end() && n1 > 0;) {
//                 if (mp2.find(it->first) != mp2.end()) {
//                     it->second--;
//                 } else {
//                     st.insert(it->first);
//                     it->second--;
//                     n1--;
//                 }
//                 if (it->second == 0) {
//                     it = mp1.erase(it);
//                 } else {
//                     ++it;
//                 }
//             }
//         }

//         for (auto it = mp2.begin(); it != mp2.end() && n2 > 0;) {
//             it->second--;
//             n2--;
//             if (it->second == 0) {
//                 it = mp2.erase(it);
//             } else {
//                 ++it;
//             }
//         }

//         for (auto i : mp1) {
//             st.insert(i.first);
//             n1--;
//             if(n1==0) break;
//         }
//         for (auto i : mp2) {
//             st.insert(i.first);
//             n2--;
//             if(n2==0) break;
//         }
        
//         return st.size();
//     }
// };



class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        // Create maps to store the frequency of each element in nums1 and nums2
        map<int, int> mp1, mp2;
        for (auto i : nums1) mp1[i]++;
        for (auto i : nums2) mp2[i]++;
        
        int n1 = nums1.size() / 2;  // Number of elements to remove from nums1
        int n2 = nums2.size() / 2;  // Number of elements to remove from nums2
        unordered_set<int> st;  // Set to store unique elements after removals
        
        int only_1 = 0, only_2 = 0, both = 0;
        
        // Count elements that are only in nums1, only in nums2, and in both
        for (auto& it : mp1) {
            if (mp2.find(it.first) != mp2.end()) { 
                both++;
            } else {
                only_1++;
            }
        }
        
        for (auto& it : mp2) {
            if (mp1.find(it.first) == mp1.end()) {
                only_2++;
            }
        }

        // Adjust only_1 and only_2 to not exceed n1/2 and n2/2 respectively
        only_1 = min(only_1, n1);
        only_2 = min(only_2, n2);

        // If only_1 does not reach n1/2, use elements from 'both'
        if (only_1 < n1) {
            int has = n1 - only_1;
            int req = min(both, has);
            both -= req;
            only_1 += req;
        }

        // If only_2 does not reach n2/2, use elements from 'both'
        if (only_2 < n2) {
            int has = n2 - only_2;
            int req = min(both, has);
            both -= req;
            only_2 += req;
        }

        // Calculate the total number of unique elements in the final set
        return only_1 + only_2;
    }
};

