class Solution {
public:
    int longestIdealString(string s, int k) {
        // dp[i] -> longest ideal subsequence from 0 to ith index 
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[1]=0;
        map<char,int>mp;
        mp[s[0]]=1;
        int answer=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                char req1 = s[i] + j;
                char req2 = s[i] - j;
                if(req1 >= 'a' && req1 <= 'z' && mp.find(req1) != mp.end()){
                    dp[i+1] = max(dp[i+1], 1 + mp[req1]);
                }
                 if(req2 >= 'a' && req2 <= 'z' && mp.find(req2) != mp.end()){
                    dp[i+1] = max(dp[i+1], 1 + mp[req2]);
                }
                
            }
            dp[i+1]= max(1, dp[i+1]);
            answer= max(dp[i+1],answer);
            mp[s[i]]= max(mp[s[i]], dp[i+1]);
        }
        for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
        return answer;

    }
};