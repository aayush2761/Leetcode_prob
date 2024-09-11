class Solution {
public:
 int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
    int minOperations(vector<int>& nums, int k) {
        int res=0;
        for(auto i : nums){
            res^=i;
        }
        return minBitFlips(res,k);
    }
};