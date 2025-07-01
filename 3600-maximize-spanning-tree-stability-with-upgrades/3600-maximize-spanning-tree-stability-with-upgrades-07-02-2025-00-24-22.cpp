class Solution {
public:
    int find(int u , vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]= find(parent[u], parent);
    }
    void setUnion(int u, int v, vector<int>&parent, vector<int>&rank ){
        int pu = find(u, parent);
        int pv= find(v, parent);
        if(pu==pv) return;
        // rank conditions 
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            rank[pu]+= 1;
            parent[pv]=pu;
        }
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // unordered_map<int,vector<pair<int,int>>>mp;
        int minStability = INT_MAX;
        vector<vector<int>>temp;
        vector<int>parent(n+1), rank(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
        for(auto & it : edges){
            if(it[3]==1){
                int u = it[0];
                int v= it[1];
                if(find(u,parent)==find(v,parent)) return -1;
                setUnion(u,v,parent,rank);
                minStability= min(minStability, it[2]);

            }
            else temp.push_back(it);
        }
        // sort 
        sort(temp.begin(), temp.end(), [](const vector<int>&a, const vector<int>&b){ return a[2]> b[2];});

        vector<int>remaningWeight;
        for(auto &it : temp){
            int u = it[0];
            int v= it[1];
            if(find(u,parent)==find(v,parent)) continue;
            setUnion(u,v,parent,rank);
           remaningWeight.push_back(it[2]);
        }
        // process only k maximum s's
         sort(remaningWeight.begin(), remaningWeight.end());
        for (int i = 0; i < remaningWeight.size() && k > 0; i++, k--) {
            remaningWeight[i] *= 2;
        }
        if(!remaningWeight.empty()){
            minStability= min(minStability, *min_element(remaningWeight.begin(), remaningWeight.end()));
        }
        // check minSpanningTree;
         int root = find(0,parent);
        for (int i = 1; i < n; i++) {
            if (find(i,parent) != root)
                return -1;
        }
         return minStability;

       
    }
};