

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        map<int, vector<int>> mpp;
        for (auto& entry : mp) {
            mpp[entry.second].push_back(entry.first);
        }

        for (auto& entry : mpp) {
            sort(entry.second.begin(), entry.second.end(), greater<int>());
        }


        vector<int> res;
        for (auto& entry : mpp) {
            int freq = entry.first;
            for (int value : entry.second) {
                for (int i = 0; i < freq; ++i) {
                    res.push_back(value);
                }
            }
        }

        return res;
    }
};
