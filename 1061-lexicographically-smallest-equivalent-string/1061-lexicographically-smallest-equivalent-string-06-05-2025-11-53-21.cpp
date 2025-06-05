class Solution {
public:
    int find(int u, vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]= find(parent[u],parent);
    }
    void unionSet(int u, int v, vector<int>&parent){
        int parent_u= find(u, parent);
        int parent_v= find(v, parent);
        if(parent_u==parent_v) return;
        // rank conditons
        if (parent_u < parent_v) {
            parent[parent_v] = parent_u;
        } else {
            parent[parent_u] = parent_v;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();

        vector<int>parent(26);
        for(int i=0;i<26;i++)parent[i]=i;
        for(int i=0;i<n;i++){
            int u= s1[i]-'a';
            int v= s2[i]-'a';
            int parent_u= find(u,parent);
            int parent_v= find(v,parent);
            if(parent_u== parent_v) {
                continue;
            }
            else{
                 unionSet(v,u,parent);

            }
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=find(baseStr[i]-'a',parent)+'a';
        }
        return baseStr;
    }
};