class Solution {
public:
     int search(vector<vector<int>>& events, int t){
        int l=0, r= events.size();
        int ans=0;
        while(l<r){
            int mid  = l+ (r-l) / 2;
            if(events[mid][0]<t){
                l = mid+1;
            }
            else r= mid;
        }
        return l;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // If you choose a job that ends at time X you will be able to start another job that starts at time X.
        // differentiating condition *****
        
        vector<vector<int>> events;
        sort(events.begin(), events.end());
        for(int i=0;i<startTime.size();i++){
            events.push_back({startTime[i],endTime[i], profit[i]});
        }
        int n = events.size();
       vector<int>dp(n+1,0);

       for(int currIndex= n-1; currIndex>=0 ; currIndex--){
            // find next index 
            // int nIndex= searchRight(events, events[currIndex][1]); upper bopund we needed 
            // int nIndex = lower_bound(events.begin(), events.end(),events[currIndex][1]))- events.begin(); -> we have to use comp 
            int nIndex= search(events, events[currIndex][1]);
            int pick = events[currIndex][2] + dp[nIndex];
            int notPick = dp[currIndex+1];
            dp[currIndex]= max(pick, notPick);
       }
       for(int i=0;i<events.size();i++) cout<<dp[i]<<" ";
       return dp[0];
    }
};