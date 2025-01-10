class Solution {
public:
    unordered_map<char, int> mp1, mp2;

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        for (auto i : words2) {
            unordered_map<char, int> temp;
            for (auto j : i) {
                temp[j]++;
            }
            for (auto it : temp) {
                mp2[it.first] = max(mp2[it.first], it.second);
            }
        }
        vector<string> res;
        for (int i = 0; i < words1.size(); i++) {
            mp1.clear(); // Clear mp1 for each word in words1
            for (auto j : words1[i]) {
                mp1[j]++;
            }
            bool flag = true;
            for (auto it = mp2.begin(); it != mp2.end(); it++) {
                if (mp1[it->first] < it->second) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(words1[i]);
        }
        return res;
    }
};
