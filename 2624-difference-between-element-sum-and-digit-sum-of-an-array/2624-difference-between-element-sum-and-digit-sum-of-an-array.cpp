class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sumn=0;
         int digits=0;
        int end= nums.size();
        for(int i=0;i<end;i++){
            sumn=sumn + nums[i];
            if(nums[i]<10){
                digits=digits+nums[i];
            }
            else{
                while(nums[i]>0){
                    digits=digits+(nums[i]%10);
                    nums[i]/=10;
                }
            }
        }
        return sumn-digits;
       
       
    }
};