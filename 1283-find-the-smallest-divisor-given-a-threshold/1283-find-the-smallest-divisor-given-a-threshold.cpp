class Solution {
public:
    int helper(vector<int>& nums, int mid){
        long long  x=0;
        for(int i=0;i<nums.size();i++){
            x+=(nums[i]+mid-1)/mid;
            
        }
        return x;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high= 1e9;
        int res=0;
        while(low<=high){
            int mid= low + (high-low) /2;
            if(helper(nums,mid)<=threshold){
                cout<<"p"<<endl;
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};