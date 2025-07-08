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
    long long maxTaxiEarnings(int nn, vector<vector<int>>& events) {
        // vector<vector<int>> events;
        // for(int i=0;i<startTime.size();i++){
        //     events.push_back({startTime[i],endTime[i], profit[i]});
        // }
        int n = events.size();
         sort(events.begin(), events.end());
       vector<long long>dp(n+1,0);

       for(int currIndex= n-1; currIndex>=0 ; currIndex--){
            // find next index 
            // int nIndex= searchRight(events, events[currIndex][1]); upper bopund we needed 
            // int nIndex = lower_bound(events.begin(), events.end(),events[currIndex][1]))- events.begin(); -> we have to use comp 
            int nIndex= search(events, events[currIndex][1]);
            long long pick = events[currIndex][2]+(events[currIndex][1]-events[currIndex][0]) + dp[nIndex];
            long long notPick = dp[currIndex+1];
            dp[currIndex]= max(pick, notPick);
       }
       for(int i=0;i<events.size();i++) cout<<dp[i]<<" ";
       return dp[0];
    }
};