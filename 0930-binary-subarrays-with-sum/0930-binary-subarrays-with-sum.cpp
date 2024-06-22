class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int k= goal;
        int ans=0,sum=0;
        unordered_map<int,int>mp;
       
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) ans++;
            if(mp.find(sum-k)!=mp.end())
                ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};