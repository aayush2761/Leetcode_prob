class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // dp[i]-> maximum score till ith index
        int n=values.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+1, values[i]+values[i-1]-1);
        }
        return dp[n-1];
    }
};



// GREEDY
// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         // greedy 
//         int res=INT_MIN;
//         int n=values.size();
//         for(int i=0;i<n;i++){
//             int temp=0;
//             for(int j=i+1;j<n;j++){
//                 temp=values[i]+values[j]+ i-j;
//                 res=max(res,temp);
//             }
//         }
//         return res;
//     }
// };