class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long res = 0;
        int n = costs.size();
        for (int i = 0; i < candidates; i++) {
            pq.push({costs[i], i});
        }
        int s = candidates;
        int t = candidates;
        int i = n - 1;
        while (t-- && i >= s) {
            pq.push({costs[i], i});
            i--;
        }
        while (k-- > 0) {
            res += pq.top().first;
            int a = pq.top().second;
            pq.pop();
            if (a < s && s <= i) {
                pq.push({costs[s], s});
                s++;
            } else if (a > i && i >= s) {
                pq.push({costs[i], i});
                i--;
            }
        }
        return res;
    }
};
