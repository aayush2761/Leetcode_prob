class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                count++;
                dfs(adj, i, vis);
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(adj, it, vis);
            }
        }
    }
};
