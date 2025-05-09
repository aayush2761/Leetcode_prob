class Solution {
public:
    #define ll long long
    ll M=1000000007;
    ll modexp(ll b, ll e) {
        ll r = 1;
        while (e) {
            if (e & 1) r = (r * b) % M;
            b = (b * b) % M;
            e >>= 1;
        }
        return r;
    }
    


    int func(int n,vector<int> &arr,int sum,int cnt,int need,vector<vector<vector<int>>> &dp){
        if(n==0){
            if(sum==0 && cnt==need)
                return 1;
            else
                return 0;
        }

        if(dp[n][sum][cnt]!=-1)
            return dp[n][sum][cnt];
        int ans=func(n-1,arr,sum,cnt,need,dp);
        if(sum>=arr[n-1] && cnt<need)
            ans=(ans+func(n-1,arr,sum-arr[n-1],cnt+1,need,dp))%M;
        return dp[n][sum][cnt]=ans;
}
    int countBalancedPermutations(string num) {
        int n=num.size();
        int sum=0;
        for(auto e:num)
            sum+=(e-'0');
        if(sum%2==1)
            return 0;
        int subsum=sum/2;
        vector<int> v;
        vector<int> freq(10);
        for(auto e:num)
            freq[e-'0']++;
        for(auto e:num)
            v.push_back((e-'0'));
        int need=0;
        if(n%2==0)
            need=n/2;
        else
            need=(n+1)/2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(subsum+1,vector<int>(need+1,-1)));
        int res=func(n,v,subsum,0,need,dp)%M;
         vector<ll> fact(n+1, 1), invf(n+1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i-1] * i % M;
        invf[n] = modexp(fact[n],M-2);
        for (int i = n; i > 0; i--)
            invf[i-1] = invf[i] * i % M;
        ll ans = res;
        ans = ans * fact[need]    % M;
        ans = ans * fact[n - need] % M;
        for (int d = 0; d < 10; d++) {
            if (freq[d] > 1)
                ans = ans * invf[freq[d]] % M;
        }
        return (int)ans;

        

    }
};