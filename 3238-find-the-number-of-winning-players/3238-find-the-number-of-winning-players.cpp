class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<string, int> mp;
        for (int i = 0; i < pick.size(); i++) {
            int person = pick[i][0];
            int color = pick[i][1];
            string key = to_string(person) + "," + to_string(color); // Creating a unique key
            mp[key]++;
        }
        int res = 0;
        unordered_set<int>st;
        for (auto& i : mp) {
            string key = i.first;
            int pos = key.find(',');
            int person = stoi(key.substr(0, pos));
            if (i.second >= person + 1) st.insert(person);
        }
        return st.size();
    }
};
