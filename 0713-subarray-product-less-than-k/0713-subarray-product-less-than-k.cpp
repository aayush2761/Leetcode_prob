class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        if(k==0) return count;
    
        int j=0;
        
        int temp=1;
       while(j<nums.size()){
        if(nums[j]<k) count++;
        else{
            j++;
            continue;
        }
        int temp=nums[j];
        int i=j+1;
        while(i<nums.size()){
            temp*=nums[i];
            if(temp<k)count++;
            else break;
            i++;
        }
        j++;
       }
        return  count;
    }
};