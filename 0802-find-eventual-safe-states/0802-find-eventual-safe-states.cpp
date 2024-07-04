class Solution {
      private:
    bool dfs(int node,vector<vector<int>>& graph ,vector<int>&vis , vector<int>&path,vector<int>&check){
        vis[node]=1;
        path[node]=1;
        check[node]=1;
        for(auto it : graph[node]){
            if(!vis[it]){
                 if(dfs(it,graph,vis,path,check)==true) {
                     check[node]=0;
                     return true;
            }
            }
            else if (path[it]){
                     check[node]=0;
                     return true;
            }
        }
        
        
        check[node]=1;
        path[node]=0;
        return false;
        
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        // same code from gfg submission 
         vector<int>safe;
       vector<int>check(V,0);
       vector<int>vis(V,0);
       vector<int>path(V,0);
       
        for(int i=0;i<V;i++){
            if(!vis[i]){
             dfs(i,graph,vis,path,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i]==1) safe.push_back(i);
        }
        return safe;


    }
};