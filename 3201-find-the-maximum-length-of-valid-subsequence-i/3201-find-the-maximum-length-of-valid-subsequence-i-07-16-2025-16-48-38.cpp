class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int even=0,odd=0;

        for(int &i:nums){
            if(i & 1) odd++;
            else even++;
        }
        int ans=1;
        int prevParity=nums[0]&1;

        for(int i=1;i<n;i++){
            int currParity=nums[i]&1;

            if(currParity!=prevParity){
                prevParity=currParity;
                ans++;
            }
        }

        return max({odd,even,ans});
    }
};