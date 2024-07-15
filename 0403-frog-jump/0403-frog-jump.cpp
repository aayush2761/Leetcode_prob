class Solution {
public:
    
    int solve(vector<int>& stones,int idx,int lastJump, vector<vector<int>>&dp){
        if(idx>=stones.size()-1){
            return true;
        }

        if(dp[idx][lastJump]!=-1) return dp[idx][lastJump];
        for(int i=idx+1;i<stones.size();i++){
            int jump=stones[i]-stones[idx];
            if(jump>lastJump+1){
                break;
            }
            if((jump==lastJump)||(jump==lastJump-1)||(jump==lastJump+1)){
                if(solve(stones,i,jump,dp)){
                    return dp[idx][lastJump]=1;
                }
            }
        }
        return dp[idx][lastJump]=0;
    }
    bool canCross(vector<int>& stones) {
    //     int n= stones.size();
    //     vector<int>dp(n+1 , 0);
    //    dp[0]= stones[0];
    //    for(int i=1;i<=n;i++){
    //     int front = dp[i+1] +  abs
    //    }
    int n = stones.size();
        
        int s= INT_MIN;
        for(int i=1;i<stones.size();i++){
            s= max(s,stones[i]-stones[i-1]);
        }
        vector<vector<int>>dp(n-1,vector<int>(2001,-1));
        if(stones[1]!=1){return false;}
         if(solve(stones,1,1,dp)) return true;
         return false;
         

    }
};
