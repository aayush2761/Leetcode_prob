class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<n;i++){
            int u = manager[i];
            int v= i;
            if(u != -1){  // head has no manager
                int wt = informTime[u];
                adj[u].push_back({v, wt});
            }
        }
        int totalTime= manager[headID];
        queue<pair<int,int>> q; 
        q.push({headID, 0});
        while(!q.empty()){
             auto [curr, timeSoFar] = q.front();
            q.pop();

            totalTime = max(totalTime, timeSoFar);

            for(auto &it : adj[curr]){
                int nxt = it.first;
                int wt = it.second;
                q.push({nxt, timeSoFar + wt});
            }
        }
        return totalTime;

    }
};