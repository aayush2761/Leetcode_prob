class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> res(n);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums1[i], i};
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        multiset<long long> ms; // Stores the k largest nums2 values encountered
        long long sum = 0; // Running sum of k largest nums2 values
        int le = 0;
        
        // Iterate through sorted nums1 values
        for (int i = 0; i < n; i++) {
            int a = v[i].first; // Current nums1 value
            int ind = v[i].second; // Original index in nums1
            
            // Process elements before index i whose nums1 values are smaller
            while (le < i && v[le].first < a) {
                long long val = nums2[v[le].second];
                
                if (ms.size() < k) { // If we have room, add it
                    sum += val;
                    ms.insert(val);
                } else if (*ms.begin() < val) { // Replace the smallest element if a larger one is found
                    sum -= *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(val);
                    sum += val;
                }
                le++;
            }
            
            res[ind] = sum; // Store the maximum sum for the current index
        }
        
        return res;
    }
};
