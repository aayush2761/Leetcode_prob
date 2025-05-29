class Solution {
public:
    void find(vector<vector<int>> &adj,int &cntEven ,int &cntOdd,vector<int> &parity){
            int c = 0; // for even
            queue<pair<int,int> > q; // to store node and its parent
            q.push({0,-1});
            
            while(!q.empty()){
                int size = q.size();
                if(c == 0)cntEven += size;
                else cntOdd += size;

                
                while(size--){
                    int node = q.front().first;
                    int parent = q.front().second;
                    parity[node] = c;
                    q.pop();

                    for(auto nodes : adj[node]){
                        if(parent != nodes){
                            q.push({nodes,node});
                        }
                    }
                }
                c  =  1-c;
            }

    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size();
        int n2 = edges2.size();

            vector<vector<int>> adj1(n1+1);
            vector<vector<int>> adj2(n2+1);

        for(int i=0;i<n1;i++){
            int u = edges1[i][0];
            int v = edges1[i][1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(int i=0;i<n2;i++){
            int u = edges2[i][0];
            int v = edges2[i][1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int> parity1(n1+1,-1);
        vector<int> parity2(n2+1,-1);

        int cntEven_1 = 0;
        int cntOdd_1 = 0;

         find(adj1,cntEven_1,cntOdd_1,parity1);

        int cntEven_2 = 0;
        int cntOdd_2 = 0;
        
        find(adj2,cntEven_2,cntOdd_2,parity2);

        int add = max(cntEven_2 ,cntOdd_2);
        vector<int> ans;
        for(int i=0;i<=n1;i++){
            if(parity1[i] == 0){ // even
                ans.push_back(cntEven_1 + add);
            }
            else ans.push_back(cntOdd_1 + add);
        }
        return ans;
    }
};