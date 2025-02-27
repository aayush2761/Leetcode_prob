class Solution {
public:
    int check(unordered_map<int,int>&mp, int a , int b){
        int x=0;
        while(true){
            int req= a+b;
            if(mp.find(req)!=mp.end()){
                x++;
                a=b;
                b=req;
            }
            else break;
        }
        return x;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        vector<vector<int>>dp(n,vector<int>(n,0));
        // diagonally 
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dp[i][j]=2+ check(mp,arr[i],arr[j]);
                res=max(dp[i][j],res);
            }
        }
        return res>2 ? res : 0;
    }
};