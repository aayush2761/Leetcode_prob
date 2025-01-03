class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n+1,0);
        // code 
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int res=0;
        for(int i=1;i<n;i++){
            double left = 1.0*pref[i];
            double right= (double)pref[n]-(double)pref[i];
            if(left>=right)res++;
        }
        return res;
    }
};