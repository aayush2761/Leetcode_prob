class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double ans=1.0*INT_MIN;
        for(int i=0;i<nums.size();i++){
            double temp=(double)nums[i];
            ans=max(ans,temp);
            for(int j=i+1;j<nums.size();j++){
                temp*=(double)nums[j];
                ans=max(ans,temp);
            }
        }
        return (int) ans;
    }
};