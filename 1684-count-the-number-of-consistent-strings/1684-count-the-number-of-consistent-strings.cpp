class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        for(auto i : allowed) mp[i]++;
        int count=0;
       for(string word : words) {
            bool isConsistent = true; // check for the consistent
            for(char c : word) {
                // if char is not there then not consistent
                if(mp.find(c) == mp.end()) {
                    isConsistent = false;
                    break;
                }
            }

            if(isConsistent) {
                count++;
            } 
        }
        
        return count;
        
    }
};