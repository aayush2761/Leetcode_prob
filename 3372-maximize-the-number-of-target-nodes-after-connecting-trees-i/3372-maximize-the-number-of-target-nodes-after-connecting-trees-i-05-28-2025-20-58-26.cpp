class Solution {
public:
    int dfs(vector<vector<int>>& adj, int k, int src, vector<bool>& vis) {
        if (k == 0) return 1;

        vis[src] = true;
        int count=1;
        for (auto it : adj[src]) {
            if (!vis[it]) {
                count+= dfs(adj, k - 1, it, vis);
            }
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n= edges1.size()+1;
        int m= edges2.size()+1;
        vector<int>dist1(n,0);
        // vector<int> adj1[n], adj2[m];
        vector<vector<int>> adj1(n), adj2(m);
        for(auto it : edges1){
            int a = it[0];
            int b = it[1];
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        for(auto it : edges2){
            int a = it[0];
            int b = it[1];
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        // computes each node distances into dist1 using tree1
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            dist1[i]= dfs(adj1, k,i,vis);
        }
        if(k==0) return dist1;
        int maxi=0;
        for(int i=0;i<m;i++){
            vector<bool>vis(m,false);
            maxi= max(maxi, dfs(adj2, k-1,i,vis));
        }
    
        for(auto &it : dist1)it+=maxi;
        return dist1;

    }
};