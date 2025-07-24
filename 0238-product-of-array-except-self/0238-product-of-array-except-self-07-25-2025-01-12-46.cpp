class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {};
        vector<int>res(n,1);
        vector<int>pref(n,1);
        vector<int>suff(n,1);
        pref[0]= nums[0];
        for(int i=1;i<n;i++){
            pref[i]= nums[i]*pref[i-1];
        }
         suff[n-1]= nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]= nums[i]*suff[i+1];
        }
        
        res[0]= suff[1];
        res[n-1] = pref[n-2];
        for(int i=1;i<n-1;i++){
            res[i]= pref[i-1]* suff[i+1];
        }
        return res;

    }
};