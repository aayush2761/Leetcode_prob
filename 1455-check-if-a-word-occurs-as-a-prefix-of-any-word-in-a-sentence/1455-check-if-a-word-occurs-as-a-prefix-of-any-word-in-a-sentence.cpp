class Solution {
public:
    bool isPrefix(const string& word1, const string& word2) {
        if (word1.size() > word2.size()) return false;
        return word2.compare(0, word1.size(), word1) == 0;
    }

    int isPrefixOfWord(string s, string key) {
        map< int,string> mp;
        int j = 0; // Start index of a word
        int index = 1; // Word index
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') { 
                string p = s.substr(j, i - j); 
                mp[index] = p;
                index++;
                j = i + 1; 
            }
        }
        // Search for the prefix
        for (auto i : mp) {
            if (isPrefix(key, i.second)) return i.first;
        }
        return -1;
    }
};
