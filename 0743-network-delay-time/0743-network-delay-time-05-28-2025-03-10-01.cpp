class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // bellmann ford 
        vector<int>dist(n+1,INT_MAX);
        dist[0]=INT_MIN;
        dist[k]=0;
        for(int i=0;i<n-1;i++){
            for(auto it : times){
                int a = it[0];
                int b = it[1];
                int wt = it[2];
                // a->b with weight
                if(dist[a]==INT_MAX) continue;
                if((wt+dist[a])<dist[b])dist[b]= dist[a]+wt;
            }
        }
        int answer=0;
        for(int i=1;i<dist.size();i++){
            if(i==k)continue;
            if(dist[i]==INT_MAX) return -1;
            answer=max(answer, dist[i]);
        }
        return answer;
    }
};