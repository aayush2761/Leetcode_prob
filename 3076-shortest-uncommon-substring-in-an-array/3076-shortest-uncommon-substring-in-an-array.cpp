class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> res;
        unordered_map<string, int> substringFrequency;

        // Step 1: Populate the map with the frequency of unique substrings
        for (const auto& str : arr) {
            unordered_set<string> seenSubstrings;
            for (size_t i = 0; i < str.size(); ++i) {
                for (size_t j = 1; j <= str.size() - i; ++j) {
                    string sub = str.substr(i, j);
                    seenSubstrings.insert(sub);
                }
            }
            // Update frequency map with substrings from the current string
            for (const auto& sub : seenSubstrings) {
                substringFrequency[sub]++;
            }
        }

        // Step 2: Find the shortest unique substring for each string in arr
        for (const auto& str : arr) {
            string shortest = "";

            for (size_t i = 0; i < str.size(); ++i) {
                for (size_t j = 1; j <= str.size() - i; ++j) {
                    string sub = str.substr(i, j);
                    if (substringFrequency[sub] == 1) {  // Check for unique substrings
                        // Check if the found substring is shorter or lexicographically smaller
                        if (shortest.empty() || sub.size() < shortest.size() || 
                            (sub.size() == shortest.size() && sub < shortest)) {
                            shortest = sub;
                        }
                    }
                }
            }

            if (!shortest.empty()) 
                res.push_back(shortest);
            else 
                res.push_back("");
        }

        return res;
    }
};
