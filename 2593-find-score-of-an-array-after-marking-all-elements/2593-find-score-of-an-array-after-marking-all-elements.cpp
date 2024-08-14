class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // element index
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        // f**kkkkkkkkkkkkkkkk
        vector<int>vis(n,false);
        
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();

            if(vis[i.second]) continue;
           vis[i.second] = true;
            res += i.first; 
            if (i.second > 0) {
                vis[i.second - 1] = true;  
            }
            if (i.second < n - 1) {
                vis[i.second+ 1] = true; 
            }
        }
        return res;

    }
};