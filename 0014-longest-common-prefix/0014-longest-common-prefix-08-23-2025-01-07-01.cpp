class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string, int> mp;

        for (int i = 0; i < strs.size(); i++) {
            string temp = "";
            for (auto j : strs[i]) {
                temp += j;
                mp[temp]++;
            }
        }

        int res = 0;
        string temp;

        for (auto i : mp) {
            if (i.second == strs.size() && i.first.size() > res) {
                res = i.first.size();
                temp = i.first;
            }
        }
        if (res == 0) return "";
        return temp;
    }
};
