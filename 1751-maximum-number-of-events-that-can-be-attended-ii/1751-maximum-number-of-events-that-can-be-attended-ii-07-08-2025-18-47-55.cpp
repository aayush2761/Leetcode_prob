class Solution {
public:
    int search(vector<vector<int>>& events, int t){
        int l=0, r= events.size();
        int ans=0;
        while(l<r){
            int mid  = l+ (r-l) / 2;
            if(events[mid][0]<=t){
                l = mid+1;
            }
            else r= mid;
        }
        return l;
    }
    int maxValue(vector<vector<int>>& events, int k) {
       sort(events.begin(), events.end());
       int n = events.size();
       vector<vector<int>>dp(k+1, vector<int>(n+1,0));

       for(int currIndex= n-1; currIndex>=0 ; currIndex--){
        for(int count=1; count<=k;count++){
            // find next index 
            // int nIndex= searchRight(events, events[currIndex][1]); upper bopund we needed 
            // int nIndex = lower_bound(events.begin(), events.end(),events[currIndex][1]))- events.begin(); -> we have to use comp 
            int nIndex= search(events, events[currIndex][1]);
            int pick = events[currIndex][2] + dp[count-1][nIndex];
            int notPick = dp[count][currIndex+1];
            dp[count][currIndex]= max(pick, notPick);
        }
       }
       return dp[k][0];

    }
};