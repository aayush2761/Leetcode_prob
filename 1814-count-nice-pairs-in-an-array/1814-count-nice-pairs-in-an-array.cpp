class Solution {
public:
    long long reverseNumber(long long num) {
    long long  rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,long long>mp;
        int n= nums.size();
        long long res=0;
        for(int i=0;i<n;i++){
            long long x = reverseNumber(nums[i]);
            mp[nums[i]-x]++;
        }
        for(auto it : mp){
            long long x = it.second;
            res+= (x*(x-1))/2;
        }
        return res % 1000000007;
    }
};