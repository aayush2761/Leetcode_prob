class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(0));
        vector<int> inDeg(n);
        for(auto& e : edges) { //build adjecent list graph
            graph[e[0]].push_back(e[1]);
            inDeg[e[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        
        vector<unordered_set<int>> ancestors(n);
        while(q.size() > 0) {
            int u = q.front(); q.pop();
            for(int v : graph[u]) {
                inDeg[v]--;
                ancestors[v].insert(u);
                for(int ancestor : ancestors[u]) {
                    ancestors[v].insert(ancestor);
                }
                if(inDeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};