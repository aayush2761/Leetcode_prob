class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int answer=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini)mini= nums[i];
            else {
                if(nums[i]-mini-fee>0){
                    answer+= nums[i]- mini- fee;
                    mini=nums[i]-fee;
                }
            }
        }
        return answer;

    }
};