
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        vector<string> vec;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            vec.push_back(word);
        }

        for (int k = 0; k < vec.size(); k++) {
            util(vec[k], dict);
        }

        string res = "";
        for (int i = 0; i < vec.size(); i++) {
            if (i != 0) res += " ";
            res += vec[i];
        }

        return res;
    }

private:
    void util(string& word, const unordered_set<string>& dict) {
        for (int len = 1; len <= word.size(); len++) {
            string prefix = word.substr(0, len);
            if (dict.find(prefix) != dict.end()) {
                word = prefix;
                return;
            }
        }
    }
};