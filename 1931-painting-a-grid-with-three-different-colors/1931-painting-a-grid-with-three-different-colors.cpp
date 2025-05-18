class Solution {
public:
void fill(int idx,int temp,int &m,vector<int> &posColor){
    if(idx>=m){
        posColor.push_back(temp);
        return;
    }
    for(int i=1;i<=3;i++){
        if(idx==0){
            fill(idx+1,temp|(i<<(2*idx)),m,posColor);
        }else{
            int pos=idx-1;
            int prev=((3<<(2*pos))&temp)>>(2*pos);
            if(prev!=i){
                fill(idx+1,temp|(i<<(2*idx)),m,posColor);
            }
        }
    }
    return;
}
const int mod=1e9+7;
long long f(int idx,int &m,int &n,int mask,vector<vector<long long>> &dp,vector<int> &posColor){
    if(idx>n){
        return 1;
    }

    if(dp[idx][mask]!=-1){
        return dp[idx][mask];
    }
    long long ans=0;
    for(int cmask:posColor){
        bool v=true;
        for(int i=0;i<m;i++){
            int val1=((3<<(2*i))&mask)>>(2*i);
            int val2=((3<<(2*i))&cmask)>>(2*i);
            if(val1==val2){
                v=false;
                break;
            }
        }
        if(v){
            ans=(ans+f(idx+1,m,n,cmask,dp,posColor))%mod;
        }
    }
    return dp[idx][mask]=ans;
}
    int colorTheGrid(int m, int n) {

        vector<int> posColor;
        int temp=0;
        fill(0,temp,m,posColor);

        vector<vector<long long>> dp(n+1,vector<long long>((1<<10),-1));
        long long ans=0;
        for(int pos:posColor){
            int mask=pos;
            ans=(ans+f(2,m,n,mask,dp,posColor))%mod;
        }
        return ans;
    }
};