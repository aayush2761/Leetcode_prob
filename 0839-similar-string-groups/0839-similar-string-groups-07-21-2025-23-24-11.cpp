class Solution {
public:
    int findParent(int u , vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]= findParent(parent[u], parent);
    }
    void  setUnion(int u, int v, vector<int>&parent, vector<int>&rank){
        int pu= findParent(u, parent);
        int pv= findParent(v, parent);
        if(pu==pv) return;
        // rank conditions 
        if(rank[pu]> rank[pv]){
            parent[pv]= pu;

        }
        else  if(rank[pu]< rank[pv]){
                parent[pu]= pv;
            }
        else {
            rank[pu]++;
            parent[pv]=pu;
        }
    }
    bool check(string &a, string &b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!= b[i])cnt++;
            if(cnt>2) return 0;
        }
        return 1;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int>parent(n), rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(strs[i], strs[j])){
                    setUnion(i,j,parent,rank);
                }
            }
        }
        // countanswer 
        int answer=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) answer++;
        }
        return answer;
    }
};