class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        if (word1.size() != word2.size()) return false;
       vector<int>arr1(26,0),arr2(26,0);
        set<char>s1,s2;
        for (int i = 0; i < word1.size(); i++) {
            arr1[word1[i] - 'a']++;
            arr2[word2[i] - 'a']++;
            s1.insert(word1[i]);
             s2.insert(word2[i]);

        }
        std::sort(arr1.begin(), arr1.end() );
        std::sort(arr2.begin(), arr2.end());
         return arr1==arr2&&s1==s2;
    }
};




// "uau"
// word2 =
// "ssx"