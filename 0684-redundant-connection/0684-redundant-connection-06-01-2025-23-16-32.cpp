class Solution {
public:
    int find(int u, vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]= find(parent[u],parent);
    }
    void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
        int parent_u= find(u, parent);
        int parent_v= find(v, parent);
        if(parent_u==parent_v) return;
        // rank conditons
        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else if(rank[parent_u] <rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else{
            parent[parent_v]= parent_u;
            rank[parent_u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n=edges.size();

        vector<int>parent(n+1), rank(n+1,0);
        for(int i=1;i<=n;i++)parent[i]=i;
        for(auto it : edges){
            int u= it[0];
            int v= it[1];
            int parent_u= find(u,parent);
            int parent_v= find(v,parent);
            if(parent_u== parent_v) {
                res.push_back(u);
                res.push_back(v);
            }
            else{
                unionSet(u,v,parent,rank);
            }
        }
        return res;
    }
};
