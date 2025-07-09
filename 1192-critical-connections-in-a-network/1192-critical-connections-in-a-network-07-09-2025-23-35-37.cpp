class Solution {
public:
    void dfs(int i ,vector<vector<int>>&adj,vector<int>&time,vector<int>&low,vector<bool>&vis,int parent,vector<vector<int>>&res, int timeCount ){
        vis[i] = true;
        time[i] = low[i] = timeCount++;

        for (auto& it : adj[i]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, adj, time, low, vis, i, res, timeCount);
                low[i] = min(low[i], low[it]);

                if (low[it] > time[i]) {
                    res.push_back({i, it});
                }
            } else {
                low[i] = min(low[i], time[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // code 
        vector<int>time(n,INT_MAX), low(n,INT_MAX);
        vector<bool>vis(n,false);
        vector<vector<int>>res;
        int timeCount=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
                dfs(0, adj, time, low, vis,-1, res,timeCount);
        //     }
        // }
        return res;
    }
};