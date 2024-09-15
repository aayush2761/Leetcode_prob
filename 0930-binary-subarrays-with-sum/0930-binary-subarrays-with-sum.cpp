class Solution {
public:
    int sliding(vector<int>& nums, int goal){
        int count=0;
        int i=0;
        int j=0;
        int temp=0;
        while(i<nums.size()){
            temp+= nums[i];
            while(temp>goal && j<=i){
                // count++;
                temp-=nums[j];
                j++;
            }
            count+= i-j+1;
            i++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sliding(nums,goal)-sliding(nums,goal-1);
    }
};