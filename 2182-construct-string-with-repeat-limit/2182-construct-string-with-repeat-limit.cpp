class Solution {
public:
    string repeatLimitedString(string s, int r) {
        unordered_map<char, int> mp;
        priority_queue<pair<char, int>> pq; 
        for (auto i : s) mp[i]++;
        for (auto i : mp) pq.push({i.first, i.second}); 

        string res = "";
        while (!pq.empty()) {
            auto i = pq.top(); pq.pop(); 
            int n = res.size();

            if (res.size() == 0 || res[n - 1] != i.first) {
                int addCount = min(r, i.second);
                for (int j = 0; j < addCount; j++) res.push_back(i.first);
                i.second -= addCount;

                if (i.second > 0) pq.push({i.first, i.second});
            } 
            else {
                if (pq.empty()) break;

                auto j = pq.top(); pq.pop(); 
                res.push_back(j.first);
                j.second--;

                if (j.second > 0) pq.push({j.first, j.second});
                pq.push({i.first, i.second});
            }
        }
        return res;
    }
};
