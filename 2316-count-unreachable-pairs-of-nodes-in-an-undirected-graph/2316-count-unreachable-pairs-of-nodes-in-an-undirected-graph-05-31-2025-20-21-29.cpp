class Solution {
public:
    int find(int u, vector<int>&parent){
        if(parent [u]==u) return u;
        return parent[u]= find(parent[u], parent);
    }
    void unite(int a, int b, vector<int>&parent, vector<int>&rank){
        int pa= find(a,parent); 
        int pb= find(b,parent);
        if(pa==pb) return;
        // rank conditions 
        if(rank[pa]>rank[pb]){
            parent[pb]=pa;
        } 
        else if(rank[pa]<rank[pb]){
            parent[pa]=pb;
        } 
        else{
            parent[pb]=pa;
            rank[pa]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int>parent(n), rank(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        for(auto & it : edges){
            int a = it[0];
            int b = it[1];
            int pa =find(a,parent);
            int pb= find(b,parent);
            if(pb==pa)continue;
            unite(a,b,parent,rank);
        }
        // key step for each and every path compression
        for (int i = 0; i < n; i++) {
            parent[i] = find(i, parent);
        }
        // for(int i=0;i<n;i++) cout<<parent[i]<<" ";

        vector<int>p(n+1,0);
        for(int i=0;i<parent.size();i++){
            p[parent[i]]++;
        }
        vector<int>temp=p;
        for(int i=n-1;i>0;i--){
            p[i]+=p[i+1];
        }
        long long answer=0;
        for(int i=0;i<n;i++){
            answer+= (long long)temp[i]* (long long)p[i+1];
        }
        return answer;


    }
};