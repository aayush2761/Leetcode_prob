class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int>stbits;
        for(auto i : nums){
            int s = __builtin_popcount(i);
            stbits.emplace_back(s);
        }
        // mapped 
        // vector<int>res;
        int n = stbits.size();
        for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stbits[j]==stbits[j+1] &&  nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    // check 
    for(int i=1;i<n;i++){
        if(nums[i]<nums[i-1]) return false;
    }
    return true;
    }
};