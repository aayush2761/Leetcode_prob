class Solution {
public:
    int find(int u, vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]= find(parent[u],parent);
    }
    void unionSet(int a, int b,vector<int>&parent,vector<int>&rank){
        int parent_a= find(a,parent);
        int parent_b= find(b,parent);
        if(parent_a==parent_b) return ;
        // rank cases 
        // bool flag=false;
        if(rank[parent_a]>rank[parent_b]){
            parent[parent_b]= parent_a;
        }
        else  if(rank[parent_a]<rank[parent_b]){
            parent[parent_a]= parent_b;
        }
        else{
            rank[parent_a]++;
            // flag=true;
            parent[parent_b]= parent_a;

        }
        // return flag;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        const int max= vals.size();
        vector<int>parent(max),rank(max,0);
        for(int i=0;i<max;i++)parent[i]=i;
       vector<vector<int>>adj(max);
       for(auto it : edges){
        int a= it[0];
        int b= it[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
        
       }
       int result=max;
       // map
       map<int,vector<int>>mp;
       for(int i=0;i<vals.size();i++){
        mp[vals[i]].push_back(i);
       }
       vector<bool> is_active(max, false); //non active in the beginning
        
        for (auto &it : mp) {
            
            vector<int> nodes = it.second;
            
            for (int &u : nodes) {
                
                for (int &v: adj[u]) {
                    if (is_active[v]) {
                        unionSet(u, v,parent,rank);
                    }
                }
                is_active[u] = true;
            }
            
            vector<int> tumhare_parents;
            
            for (int &u : nodes) 
                tumhare_parents.push_back(find(u,parent));
            
            sort(tumhare_parents.begin(), tumhare_parents.end());
                        
            int sz = tumhare_parents.size();
            
            for (int j = 0; j < sz; j++) {
                long long count = 0;
                
                int cur_parent = tumhare_parents[j];
                
                while (j < sz && tumhare_parents[j] == cur_parent) {
                    j++, 
                    count++;
                }
                j--;
                
                result += (count * (count - 1))/2;
            }
        }
        
        return result;

    }
};