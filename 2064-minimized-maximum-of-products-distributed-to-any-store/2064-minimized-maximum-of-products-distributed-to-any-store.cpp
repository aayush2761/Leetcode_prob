class Solution {
public:
int helper(int n, vector<int>& nums, int mid){
    int count=0;
    for(int i=0;i<nums.size();i++){
        count+=(nums[i]+mid-1)/mid;
       
    }
    return count<=n;
}
    int minimizedMaximum(int n, vector<int>& nums) {
        int low=1,high=1e9;
        int res=0;
        while(low<=high){
            int mid=low+(high-low) /2;
            if(helper(n,nums,mid)){
                res=mid;
               high=mid-1;
            }
            else  low=mid+1;
        }
        return res;
    }
};