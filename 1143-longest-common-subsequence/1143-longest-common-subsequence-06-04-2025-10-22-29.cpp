class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // pick non_pick 
        // dp[i][j] -> longest subsequence from the string till the ith index from string 1 and string j of 2 string 
        int text1Size= text1.size();
        int text2Size= text2.size();
        vector<vector<int>>dp(text1Size+1, vector<int>(text2Size+1,0));
        for(int i=1;i<=text1Size;i++){
            for(int j=1;j<=text2Size ; j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=1 + dp[i-1][j-1];
                else dp[i][j]+= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // for(int i=0;i<=text1Size;i++){
        //     for(int j=0;j<=text2Size ; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[text1Size][text2Size];
    }
};