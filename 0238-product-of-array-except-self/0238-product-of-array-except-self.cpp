class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n+1,1), suff(n+1,1);
        // pref
        for(int i=1;i<=n;i++) pref[i]= pref[i-1]*nums[i-1];
        for(int i=n-1;i>=0;i--) suff[i]= suff[i+1]*nums[i];
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i]= pref[i]*suff[i+1];
        }
        return res;
    }
};