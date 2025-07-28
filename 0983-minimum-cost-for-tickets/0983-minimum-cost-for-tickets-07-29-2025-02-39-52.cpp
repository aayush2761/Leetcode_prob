class Solution {
public:
    vector<int>dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       dp.assign(366,0);
       set<int>st(days.begin(), days.end());
       for(int i=1;i<366;i++){
        if (!st.count(i)) {
                dp[i] = dp[i - 1];
                continue;
        }
        int one = costs[0] + dp[i - 1];
            int seven = costs[1] + dp[max(0, i - 7)];
            int thirty = costs[2] + dp[max(0, i - 30)];
            dp[i] = min({one, seven, thirty});
        
       }
       return dp[days.back()];

    }
};