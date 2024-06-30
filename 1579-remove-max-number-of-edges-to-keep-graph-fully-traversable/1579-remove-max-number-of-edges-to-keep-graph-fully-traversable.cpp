class Solution {
public:
    int findParent(vector<int>& parent, int u) {
        if(parent[u] < 0)
            return u;
        return parent[u] = findParent(parent, parent[u]);
    }
    bool UnionByWeight(vector<int>& parent, int u, int v) {
        int pu = findParent(parent, u), pv = findParent(parent, v);
        if(pu == pv)
            return false;
        if(parent[pu] < parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parent(n + 1, -1);
        int remove = 0;
        for(vector<int>& edge: edges)
            if(edge[0] == 3 && !UnionByWeight(parent, edge[1], edge[2]))
                    remove++;
        vector<int> a(parent), b(parent);
        for(vector<int>& edge: edges) {
            if(edge[0] == 1 && !UnionByWeight(a, edge[1], edge[2]))
                    remove++;
            else if(edge[0] == 2 && !UnionByWeight(b, edge[1], edge[2]))
                    remove++;
        }
        int groupa = 0, groupb = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] < 0)
                groupa++;
            if(b[i] < 0)
                groupb++;
        }
        if(groupa > 1 || groupb > 1)
            return -1;
        return remove;
    }
};
// copy paste :((