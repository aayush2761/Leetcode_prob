class Solution {
public:
    vector<vector<int>>dp;
    int solve( vector<int>& cuts, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k= i;k<=j;k++){
            int steps = cuts[j+1]- cuts[i-1] + solve(cuts,i,k-1)+ solve(cuts, k+1, j);
            mini= min(steps, mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int s= cuts.size();
        dp.assign(s, vector<int>(s,-1));
        return solve(cuts, 1, cuts.size()-2);
    }
};