class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<bool>isans(n, false);
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(nums[i-1]== nums[i] && isans[i-1]){
                // ans++;
                isans[i]= true;
                continue;
            }
            int left = nums[i-1];
            int right =-1;
            int j= i+1;
            while(j<n && nums[i]== nums[j]){
                j++;
            }
            if(j==n) break;
            right = nums[j];
            if(nums[i]> left && nums[i]> right) {
                ans++;
                isans[i]= true;
            }
            if(nums[i]<left && nums[i]< right) {
                ans++;
                isans[i]= true;
            }

        }
        for(int i=0;i<n;i++) cout<<isans[i]<<" ";
        return ans;
    }
};