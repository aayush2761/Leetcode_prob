class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int e=nums.size();
        if (e <= 2) {
            return e;
        }
       int index = 2;  
        for (int i = 2; i < e; i++) {
            if (nums[i] != nums[index - 1] || nums[i] != nums[index - 2]) {
                nums[index++] = nums[i];
            }
        }

        return index;
    }
    
};