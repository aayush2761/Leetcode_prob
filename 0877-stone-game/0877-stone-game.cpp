class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // dp[i][j]-> it states that i, j array size is remainingand out of which what i can get 
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0)); 
        vector<int>pref(n+1,0);
        for(int i=1;i<n;i++)pref[i]+=pref[i-1]+piles[i-1];
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(i==j)dp[i][j]=piles[i];
                else if(i<j){
                    dp[i][j]= piles[i] + (pref[j+1]-pref[i+2]) - dp[i+1][j];
                dp[i][j]= max(dp[i][j],  piles[j] + (pref[j]-pref[i+1]) - dp[i][j-1]);
                }
            }
        }
        int total = accumulate(piles.begin(),piles.end(),0);
        if(dp[0][n-1]> total/2)return true;
        return false;
    }
};