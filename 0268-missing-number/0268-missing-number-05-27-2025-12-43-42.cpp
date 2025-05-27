class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missingNumber=0;
        for(int i=0;i<n;i++){
            missingNumber^=(i^nums[i]);
        }
        missingNumber^=(n);
        return missingNumber;
    }
};