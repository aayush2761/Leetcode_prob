class Solution {
public:
    struct comparator {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) 
                return a.second > b.second;  // Lesser index has higher priority
            return a.first < b.first;  // Max element has higher priority
        }
    };

    int largestRectangleArea(vector<int>& heights) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first > heights[i]) {
                auto x = pq.top();
                pq.pop();
                res = max(res, x.first * (i - x.second));
            }
            pq.push({heights[i], i});
        }
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            res = max(res, x.first * (n - x.second));
        }

        return res;
    }
};
