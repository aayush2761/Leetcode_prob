class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftH(n), rightH(n);
        int left=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>left){
                leftH[i]=nums[i];
                left=nums[i];
            }
            else leftH[i]=left;
        }
        int right=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>right){
                rightH[i]=nums[i];
                right=nums[i];
            }
            else rightH[i]=right;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= min(leftH[i],rightH[i])-nums[i];
        }
        return ans;
    }
};