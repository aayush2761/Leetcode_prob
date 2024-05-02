class Solution {
public:
    int findMaxK(vector<int>& nums) {
        //edge cases
        if(nums.size()==1 || nums.size()==0) return -1;
        if(nums.size()==2){
            if(nums[0]+nums[1]!=0) return -1;
            else return nums[1];
        }
        sort(nums.begin(),nums.end());
        //two more edge case 
        if(nums[0]>0) return -1;
        if(nums[nums.size()-1]<0) return -1;
        int i= nums.size()-1;
        int j= 0;
        int temp=-1;
        while(nums[j]<0){
            if(nums[i]+nums[j]==0){
                temp=nums[i];
                break;
            }
            else{
                --i;
            }
             if(nums[i]<0){ 
                ++j;
                i=nums.size()-1;}
        }
        return temp;
    }
};