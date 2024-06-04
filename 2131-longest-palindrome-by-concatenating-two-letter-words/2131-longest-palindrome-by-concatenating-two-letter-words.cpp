class Solution {
public:
    int longestPalindrome(std::vector<std::string>& words) {
        int res = 0;
        std::unordered_map<std::string, int> mp;
        int middle = 0;

        for (auto &word : words) {
            std::string rev = word;
            std::reverse(rev.begin(), rev.end());

            if (mp[rev] > 0) {
                res += 4;
                mp[rev]--;
                if (mp[rev] == 0) {
                    mp.erase(rev);
                }
            } else {
                mp[word]++;
            }
        }

        for (const auto &entry : mp) {
            if (entry.second > 0 && entry.first[0] == entry.first[1]) {
                middle = 2;
                break;
            }
        }

        return res + middle;
    }

};