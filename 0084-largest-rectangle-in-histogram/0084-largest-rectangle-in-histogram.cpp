class Solution {
public:
    int solve(vector<int>& t){
       int res = 0;
        int n = t.size();
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() && st.top().first > t[i]) {
                auto [height, idx] = st.top();
                st.pop();
                res = max(res, height * (i - idx));
                start = idx;
            }
            st.push({t[i], start});
            res = max(res, t[i] * (i - start + 1));
        }

        return res;
    }
    int largestRectangleArea(vector<int>& t) {
        int n = t.size();
        int res1= solve(t);
        reverse(t.begin(),t.end());
        int res2= solve(t);
         int d= *min_element(t.begin(),t.end());
         int c= *max_element(t.begin(),t.end());
         return max({res1, res2,c,d*n});
    }
};