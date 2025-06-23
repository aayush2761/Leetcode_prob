class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int answer=0;
        int mini=INT_MAX;
        // buy option -> nums[i]- fees 
        // sell option nums[i]- prev -> sole profit 
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini)mini= nums[i];
            else {
                if(nums[i]-mini-fee>0){
                    answer+= nums[i]- mini- fee;
                    mini=nums[i]-fee;//wapas se ussi din karid liya bhai 
                }
            }
            // cout<<"nums->"<<nums[i]<<" "<<"mini->"<<mini<<" "<< "answer->" <<answer<<endl;
        }
        return answer;

    }
};