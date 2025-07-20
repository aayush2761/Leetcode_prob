class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m= word2.size();
        // dp[i][j] -> min operations required to convert word1 of length i to word2 of length j 
        vector<vector<int>>dp(n+1, vector<int>(m+1,INT_MAX));
        for(int i=0;i<=n;i++) dp[i][m]=n-i;
        for(int j=0;j<=m;j++) dp[n][j]=m-j;
        // code 
        for(int i=n-1;i>=0 ;i--){
            for(int j=m-1;j>=0;j--){
                  int answer = INT_MAX;
                if(word1[i]==word2[j])dp[i][j]= dp[i+1][j+1];
                else{
                      // insert case 
                    answer = min(answer, 1+ dp[i][j+1]);
                    // delete case 
                    answer= min(answer, 1+ dp[i+1][j]);
                    // replace 
                    answer= min(answer, 1+ dp[i+1][j+1]);

                    dp[i][j]=answer;
                }
            }
        }
        return dp[0][0];

    }
};