class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // adjancey list 
        int n= colors.size();
        // vector<int>colorArray(26,0);
        vector<vector<int>>maxi(n,vector<int>(26,0)); // store the maximum colors 
        vector<int>adj[n];
        vector<int>IncomingEdges(n,0);
        for(auto it:  edges){
            int a = it[0];
            int b = it[1];
            IncomingEdges[b]++;
            // a->b;
            adj[a].push_back(b);
        }
        queue<int>q;
         int nodeCount=0;
        for(auto it : IncomingEdges ){
            if(it==0){
                q.push(it);
                maxi[it][colors[it]-'a']=1;
                nodeCount++;
            }
        }
        int ans=1;
       
        while(!q.empty()){
            int current= q.front();
            q.pop();
            for(auto it: adj[current]){
                int element = it;
                IncomingEdges[element]--;
                for(int i=0;i<26;i++){
                    if(colors[element]-'a'==i)maxi[element][i]= 1+maxi[current][i];
                    else maxi[element][i]= maxi[current][i];
                    ans=max(ans,maxi[element][i]);
                }
                if(IncomingEdges[element]==0){
                     q.push(element);
                     nodeCount++;
                }
            }
        }
        if(nodeCount<n) return -1;
        return ans;
    }
};