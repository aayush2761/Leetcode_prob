class Solution {
public:
    bool isValid(map<char, int>& temp, map<char, int>& mpt) {
        for (auto& [ch, cnt] : mpt) {
            if (temp[ch] < cnt) return false;
        }
        return true;
    }

    bool check(int mid, map<char, int>& mpt, string s, string& resString) {
        int i = 0, j = 0;
        map<char, int> temp;

        while (i < s.size()) {
            if (mpt.find(s[i]) != mpt.end()) temp[s[i]]++;

            if (i - j + 1 == mid) {
                if (isValid(temp, mpt)) {
                    resString = s.substr(j, mid);
                    return true;
                }

                if (mpt.find(s[j]) != mpt.end()) {
                    temp[s[j]]--;
                    if (temp[s[j]] == 0) temp.erase(s[j]);
                }
                j++;
            }
            i++;
        }
        return false;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        map<char, int> mpt;
        for (auto& it : t) mpt[it]++;

        string resString = "";
        int low = t.size(), high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            string tempRes = "";
            if (check(mid, mpt, s, tempRes)) {
                if (resString == "" || tempRes.size() < resString.size())
                    resString = tempRes;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return resString;
    }
};
