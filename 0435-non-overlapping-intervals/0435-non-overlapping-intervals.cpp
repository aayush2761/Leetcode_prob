typedef long long ll;
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define all(x) x.begin(), x.end()
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
         vector<pair<pair<ll,ll>,ll>>v(n);
        for(int i=0;i<n;i++){
           
            v[i]= {{intervals[i][0],intervals[i][1]},1};
        }
        sort(all(v), [&](auto aa , auto bb){
            return aa.first.second < bb.first.second;
        });
        //  dp[i]-> maximum sum till the ith index from 0 
        vector<ll> dp(n, 0);
        dp[0] = v[0].second;

        foreach(i,1,n,1){
            auto index = [&]() {
                ll low = 0, high = i - 1, ans = -1;
                while(low <= high) {
                    ll mid = low + (high - low) / 2;
                    if(v[mid].first.second <= v[i].first.first) {
                        ans = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return ans;
            };

            ll prevIndex = index();
            ll take = v[i].second + (prevIndex == -1 ? 0 : dp[prevIndex]);
            ll skip = dp[i-1];
            dp[i] = max(take, skip);
        }

        // out(dp[n-1]);
        return n- dp[n-1];
    }
};