class Solution {
public:
    int maximumCount(vector<int>& nums) {
       
        int n= nums.size();
         int index=n;
        int low=0,high = n-1;
        if(n==1){
            if(nums[0]==0) return 0;
            else return 1;
        }
        
        while(low<=high){
            int mid= low + (high-low) /2;
            // if(mid!=n-1 && mid!=0 && nums[mid-1]<0 && nums[mid+1]>=0){
            //     index=mid;
            //     break;
            // }
            // else if (mid >0 && nums[mid-1]>=0 && nums[mid]>=0) high = mid-1;
            // else low= mid+1;
            if (nums[mid] >= 0) {
                index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int neg = index;
        while(nums[index]==0)index++;
        return max(neg, n-index);
        

    }
};