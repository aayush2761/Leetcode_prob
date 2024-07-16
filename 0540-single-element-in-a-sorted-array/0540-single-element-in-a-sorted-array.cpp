class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2 && nums[0]==nums[1]) return -1;
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        
        int l=0;
        int h= nums.size()-1;
        while(l<=h){
            int  mid= l +(h-l) /2;
            if((nums[mid]!=nums[mid-1])&& (nums[mid]!=nums[mid+1])){
                return nums[mid];
            }
           // left 
           else if((nums[mid]==nums[mid-1]) && mid%2!=0 ){
                l=mid+1;
                
           }
           else if((nums[mid]==nums[mid-1]) && mid%2==0 ){
                h=mid-2;
           }
           else if ((nums[mid]==nums[mid+1]) && mid%2==0)  l=mid+2;
           else h=mid-1;
        }
        return -1;
    }
};