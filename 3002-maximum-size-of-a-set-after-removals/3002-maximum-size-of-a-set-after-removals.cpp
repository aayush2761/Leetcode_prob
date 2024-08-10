class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1;
        for (auto i : nums1) mp1[i]++;
        map<int, int> mp2;
        for (auto i : nums2) mp2[i]++;
        
        int n1 = nums1.size() / 2;
        int n2 = nums2.size() / 2;
        unordered_set<int> st;

        while (n1 > 0) {
            for (auto it = mp1.begin(); it != mp1.end() && n1 > 0;) {
                if (mp2.find(it->first) != mp2.end()) {
                    it->second--;
                } else {
                    st.insert(it->first);
                    it->second--;
                    n1--;
                }
                if (it->second == 0) {
                    it = mp1.erase(it);
                } else {
                    ++it;
                }
            }
        }

        for (auto it = mp2.begin(); it != mp2.end() && n2 > 0;) {
            it->second--;
            n2--;
            if (it->second == 0) {
                it = mp2.erase(it);
            } else {
                ++it;
            }
        }

        for (auto i : mp1) {
            st.insert(i.first);
            n1--;
            if(n1==0) break;
        }
        for (auto i : mp2) {
            st.insert(i.first);
            n2--;
            if(n2==0) break;
        }
        
        return st.size();
    }
};
