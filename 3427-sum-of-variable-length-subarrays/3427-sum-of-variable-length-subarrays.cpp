class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int res=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int start= max(0,i-nums[i]);
            int temp=0;
            for(int j=start;j<=i;j++){
                temp+=nums[j];
            }
            res+=temp;
        }
        return res;
    }
};