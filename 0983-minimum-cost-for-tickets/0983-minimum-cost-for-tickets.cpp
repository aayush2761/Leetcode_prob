class Solution {
public:
    unordered_set<int>travel;
    unordered_map<int,int>passValidity;
    int dp[366][4][366];
    int solve(int dno, int pass , int lastBuy,vector<int>&costs){
        if(dno==366)return 0;
        if(dp[dno][pass][lastBuy]!=-1) return dp[dno][pass][lastBuy];
        if(travel.find(dno)==travel.end()){
            return dp[dno][pass][lastBuy]=solve(dno+1,pass,lastBuy,costs);
        }
        else{
            bool own = (dno<(lastBuy+passValidity[pass]) ? 1 :0);
            if(own){
                return dp[dno][pass][lastBuy]=solve(dno+1,pass,lastBuy,costs);
            }
            else {
                int op1= costs[0] + solve(dno+1,1,dno,costs);
                int op2= costs[1] + solve(dno+1,2,dno,costs);
                int op3= costs[2] + solve(dno+1,3,dno,costs);
                return dp[dno][pass][lastBuy]=min({op1,op2,op3});
            }
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        passValidity[0]=0;
        passValidity[1]=1;
        passValidity[2]=7;
        passValidity[3]=30;
        travel.clear();
        for(auto i: days)travel.insert(i);
        memset(dp,-1,sizeof(dp));
        return solve(1,0,0,costs);

    }
};
// dp[dno][pass][lastBuy]