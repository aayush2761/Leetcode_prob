class Solution {
public:
    int dp[14][14][1<<14];
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 1;
        function<int(int,int,int)> dfs = [&](int a,int b,int mask)->int{
            if(dp[a][b][mask]!=-1) return dp[a][b][mask];
            if(dp[b][a][mask]!=-1) return dp[b][a][mask];
            int res = 0;
            for(auto &c:adj[a]){
                if(mask>>c & 1) continue;
                for(auto &d:adj[b]){
                    if((mask>>d & 1) | (c==d)) continue;
                    if(label[c]==label[d]) res = max(res,2 + dfs(c,d,(mask | (1<<c)) | (1<<d)));
                }
            }
            dp[a][b][mask] = res;
            dp[b][a][mask] = res;
            return res;
        };
        for(int i=0;i<n;i++) ans = max(ans,1 + dfs(i,i,1<<i));
        for(auto e:edges){
            int u = e[0] , v = e[1];
            if(label[u]==label[v]) ans = max(ans,2 + dfs(u,v,(1<<u) | (1<<v)));
        }
        return ans;
    }
};