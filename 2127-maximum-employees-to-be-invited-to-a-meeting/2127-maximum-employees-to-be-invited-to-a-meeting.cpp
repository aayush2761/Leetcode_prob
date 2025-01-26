class Solution {
private:
    int findMaxCycle(vector<int>& favorites) {
        int n = favorites.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            vector<int> cycle;
            int curr = i;
            while (!visited[curr]) {
                cycle.push_back(curr);
                visited[curr] = true;
                curr = favorites[curr];
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == curr) {
                    ans = max(ans, (int)cycle.size() - k);
                    break;
                }
            }
        }
        return ans;
    }
    int topologicalSortAndPairSum(vector<int>& favorites) {
        int n = favorites.size();
        vector<int> ind(n, 0);
        vector<int> d(n, 1);
        for (int fav : favorites)
            ++ind[fav];

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (ind[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            d[favorites[curr]] =
                max(d[favorites[curr]], d[curr] + 1);

            if (--ind[favorites[curr]] == 0) {
                q.push(favorites[curr]);
            }
        }

        int pairSum = 0;
        for (int i = 0; i < n; ++i) {
            if (i == favorites[favorites[i]]) {
                pairSum += d[i];
            }
        }
        return pairSum;
    }
public:
    int maximumInvitations(vector<int>& favorite) {
        return max(findMaxCycle(favorite), topologicalSortAndPairSum(favorite));
    }
};