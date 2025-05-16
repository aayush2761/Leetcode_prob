class Solution {
public:
    bool check(string &a, string &b){
        int count = 0;
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) count++;
            if(count > 1) return false;
        }
        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<pair<int,int>> dp(n, {1, -1}); // initialize with length 1

        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(check(words[i], words[j]) && groups[i] != groups[j]) {
                    if(dp[j].first + 1 > dp[i].first) {
                        dp[i] = {dp[j].first + 1, j};
                    }
                }
            }
        }

        int index = -1, res = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i].first > res) {
                res = dp[i].first;
                index = i;
            }
        }

        vector<string> ans;
        while(index != -1) {
            ans.push_back(words[index]);
            index = dp[index].second;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
