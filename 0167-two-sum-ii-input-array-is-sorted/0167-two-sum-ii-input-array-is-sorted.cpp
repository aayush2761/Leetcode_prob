class Solution {
public:
    int bs(vector<int>& nums,int key){
        int res=0;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low +(high-low) /2;
            if(nums[mid]==key)return mid+1;
            else if (nums[mid]>key)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            int x= bs(nums,target-nums[i]);
            if(x!=-1 && x!=i+1){
                if(x>i+1)return {i+1,x};
                else return {x,i+1};
            }
        }
        return {};
    }
};