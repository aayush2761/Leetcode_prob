class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int mid = s + (e-s)/2;
            // if((nums[mid]<nums[(mid-1)%n]) && nums[mid]<nums[(mid+1)%n]){

            // }
            // else if(nums[mid]>nums[s]) e--;
            // else s++;
             if (nums[mid] < nums[e]) {
                e = mid;
            }
            else if (nums[mid] > nums[e]) {
                s = mid + 1;
            }
           
            else {
                e--;
            }
        }

        return nums[s];
        
    }
};