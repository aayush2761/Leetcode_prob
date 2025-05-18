class Solution {
public:
    bool check(unordered_map<char, int>& mps, unordered_map<char, int>& mpt) {
        for(auto i : mpt) {
            if(mps[i.first] < i.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> mps, mpt;
        for(auto i : t) mpt[i]++;
        
        int mini = INT_MAX;
        string res = "";
        int i = 0, j = 0;

        // Sliding window
        while(i < s.size()) {
            mps[s[i]]++;  

           
            while(check(mps, mpt)) {
              
                if(mini > i - j + 1) {
                    mini = i - j + 1;
                    res = s.substr(j, mini);
                }
               
                mps[s[j]]--;
                j++;
            }
            i++;
        }
        return res;
    }
};
