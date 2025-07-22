class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=0;
         for(auto &it : nums) i^= it;
         return i;
    }
};