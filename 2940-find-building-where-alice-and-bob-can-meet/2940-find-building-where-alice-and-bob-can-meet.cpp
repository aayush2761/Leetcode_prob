// class Solution {
// public:
//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         int n = heights.size();
//         vector<int> v(n, -1);
//         stack<pair<int, int>> st;

//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && heights[i] >= st.top().first) {
//                 st.pop();
//             }
//             if (!st.empty()) {
//                 v[i] = st.top().second;
//             }
//             st.push({heights[i], i});
//         }

//         vector<int> res;
//         for (auto& q : queries) {
//             int left = q[0];
//             int right = q[1];

//             if (left == right) {
//                 res.push_back(left);
//             } else if (heights[min(left, right)] < heights[max(left, right)]) {
//                 res.push_back(max(left, right));
//             } else if (v[left] == -1 || v[right] == -1) {
//                 res.push_back(-1);
//             } else {
//                 res.push_back(v[max(left, right)]);
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<pair<int, int>> monoStack;
        vector<int> result(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            else
                newQueries[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();
            monoStack.push_back({heights[i], i});
        }
        return result;
    }

private:
    int search(int height, vector<pair<int, int>>& monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};