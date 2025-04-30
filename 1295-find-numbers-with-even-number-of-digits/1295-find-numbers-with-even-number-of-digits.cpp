class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            int digits = log10(nums[i])+1;
            if((digits&1) ==0)cnt++;
        }
        return cnt;
    }
};