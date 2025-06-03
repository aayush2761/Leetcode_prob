class Solution {
public:
     bool checkPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int answer=0;
        for(int i=0;i<n;i++){
            for(int j= n-1;j>=i;j--){
                if(i==j){
                    dp[i][j]=true;
                    answer++;
                }
                else{
                    string temp= s.substr(i, j-i+1);
                    if(checkPalindrome(temp)){
                        dp[i][j]=true;
                        answer++;
                    }
                    // answer=max(answer, i-j+1);
                }
            }
        }
        return answer;
    }
};