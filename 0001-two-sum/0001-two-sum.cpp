class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int e= nums.size();
       vector<int> result(2, -1);
       for(int i=0;i<e-1;i++){
           
           for(int j=i+1;j<e;j++){
               if(nums[i]+nums[j]==target){
                   result[0]=i;
                   result[1]=j;
                    break;
               }
           }
       }
       return result;
    }
};