class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        long long temp=0;
        while(i<nums.size()-1){
            temp+=nums[i];
            i++;
        }
        int j=nums.size()-1;
        while(j>1){
            if(nums[j]<temp) {
                return temp+ nums[j];
                break;
            }
            else{
                j--;
                temp=temp-nums[j];
            }
        }
        return -1;
    }
};