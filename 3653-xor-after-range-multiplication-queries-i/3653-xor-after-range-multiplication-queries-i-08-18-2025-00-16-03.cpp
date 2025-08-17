class Solution {
public:
    const int mod = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto & it : queries){
            int l= it[0];
            int r= it[1];
            int k= it[2];
            int v= it[3];

            while(l<=r){
                nums[l] = ((long long)nums[l]*(long long)v)%mod;
                l+=k;
            }
        }
        int ans=0;
        for(auto &it : nums){
            ans^= it;
        }
        return ans;
    }
};