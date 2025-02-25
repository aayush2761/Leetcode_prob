class Solution {
public:
    int countSubarray(vector<int>&nums, int k){
        int res=0;
        int i=0;
        int j=0;
        int n= nums.size();
        unordered_map<int,int>mp;
        while(j<=i && i<n){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                j++;
            }
            res+= (i-j+1);
            i++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& v, int k) {
         return  countSubarray(v,k)-countSubarray(v,k-1);
    }
};