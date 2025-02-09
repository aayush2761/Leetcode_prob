class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long res=((long long)n*(long long)(n-1))/2;
        unordered_map<int,long long>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-i]++;
        }
        for(auto it : mp){
            long long x = it.second;
            res-= (x*(x-1))/2;
        }
        return res;
        
    }
};
// brute force -> n*n (tc) -> go for the two loops 
// 