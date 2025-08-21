class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        // transition equation -> dp[i][j]= true if s[i]==s[j] && dp[i+1][j-1]== true;
        string answer="";
        for(int len =1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j = i+len-1;// 0based 
                if(i==j){
                        dp[i][j]=true;
                }
                else if(i+1 ==j){
                    dp[i][j]= (s[i]==s[j]);// 2 len 
                }
                else {
                    // > 2 length 
                    dp[i][j]= (s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]){
                    // naswer= max(annswer, j-i+1);
                    string temp = s.substr(i, j-i+1);
                    if(temp.size()>answer.size())answer=temp;
                }
            }
        }
        return answer;
    }
};