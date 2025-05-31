class Solution {
public:
    int find(int u, vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]= find(parent[u],parent);
    }
    void unionSet(int a, int b,vector<int>&parent,vector<int>&rank){
        int parent_a= find(a,parent);
        int parent_b= find(b,parent);
        if(parent_a==parent_b) return;
        // rank cases 
        if(rank[parent_a]>rank[parent_b]){
            parent[parent_b]= parent_a;
        }
        else  if(rank[parent_a]<rank[parent_b]){
            parent[parent_a]= parent_b;
        }
        else{
            rank[parent_a]++;
            parent[parent_b]= parent_a;

        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
         const int max= 1e5+5;
        vector<int>parent(max),rank(max,0);
        for(int i=0;i<max;i++)parent[i]=i;
        int edgeSize= connections.size();
        if(n-1>edgeSize) return -1;
        int connectionRequired=n-1;
        for(auto & it : connections){
            int u= it[0];
            int v= it[1];
            int parent_u= find(u,parent);
            int parent_v= find(v,parent);
            if(parent_u!=parent_v) {
                 unionSet(u,v,parent,rank);
                connectionRequired--;
            }
           
        }
        return connectionRequired;
    }
};