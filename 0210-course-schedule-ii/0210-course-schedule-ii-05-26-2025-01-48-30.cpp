class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
            int V=N;
	   vector<std::vector<int>> adj(N);
	  for (const auto& prerequisite : prerequisites) {
       int u = prerequisite[1];
            int v = prerequisite[0];
        adj[u].push_back(v);
    
    }
	      vector<int> inDegree(V, 0);
	    
	    for(int i=0;i<N;i++){
	        for(auto it : adj[i]) inDegree[it]++;
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it: adj[node]){
	            inDegree[it]--;
	            if(inDegree[it]==0) q.push(it);
	        }
	    }
	    if(topo.size()==N) return topo;
	    return {};
    }
};