class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==1) continue;
            if(nums[i]==0 && nums[i+1]==1 && nums[i+2]==1  ){
                nums[i]=1;
                nums[i+1]=0;
                nums[i+2]=0;
                
                res++;
            }
            else if (nums[i]==0 && nums[i+1]==0 && nums[i+2]==1){
                nums[i]=1;
                nums[i+1]=1;
                nums[i+2]=0;
                res++;
            }
            else if (nums[i]==0 && nums[i+2]==0 && nums[i+1]==0){
                nums[i]=1;
                nums[i+1]=1;
                nums[i+2]=1;
                res++;
            }
             else if (nums[i]==0 && nums[i+2]==0 && nums[i+1]==1){
                nums[i]=1;
                nums[i+1]=0;
                nums[i+2]=1;
                res++;
            }
        }
        int n=nums.size();
        if(nums[n-1]==0 || nums[n-2]==0) return -1;
        return res;
    }
};