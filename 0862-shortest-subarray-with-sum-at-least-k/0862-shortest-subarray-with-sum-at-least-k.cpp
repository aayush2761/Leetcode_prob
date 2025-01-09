class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n= nums.size();
        deque<int>dq;
        vector<long long>pref(n+1,0);
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            pref[i+1]=nums[i]+pref[i];
            if(pref[i+1]>=k){
                res=min(res,i+1);
            }
            // shringking phase 
            while(!dq.empty()&& pref[i+1]-pref[dq.front()]>=k){
                res=min(res,i+1-dq.front());
                dq.pop_front();
            }
            // monmotonic nature
            while(!dq.empty()&& pref[i+1]<=pref[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i+1);

        }
        return res==INT_MAX ? -1 : res;
    }
};