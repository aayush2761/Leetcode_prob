class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(auto i:nums)st.insert(i);
        int k=st.size();
        //question is find subarray with k different elements
        int ans=0;
        unordered_map<int,int>mp;
        for(int l=0,r=0;r<nums.size();r++){
            mp[nums[r]]++;
            if(mp.size()==k) ans++;
            if(r==nums.size()-1){
                r=l;
                l++;
                
                mp.clear();
            }
        }
        return ans;

        
    }
};