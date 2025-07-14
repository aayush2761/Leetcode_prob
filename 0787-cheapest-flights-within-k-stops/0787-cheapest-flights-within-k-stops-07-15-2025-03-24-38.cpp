class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // deciding factor -> how will i choose the points so that i can keep an eye on the k stops given in the Qs
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it : flights){
            adj[it[0]].push_back({it[1],it[2]}); // i-> j,w
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});// cost, src, hops 
        vector<int> distance(n+1,INT_MAX);
        while(!pq.empty()){
            auto [cost, p] = pq.top(); pq.pop();
            int node = p.first, hops = p.second;

            if (node == dst) return cost;
            if (hops > k || hops > distance[node]) continue;
            distance[node] = hops;

            for (auto& [nei, wt] : adj[node]) {
                pq.push({cost + wt, {nei, hops + 1}});
            }
        }
        // if(dist[])
        return -1;
    }
};