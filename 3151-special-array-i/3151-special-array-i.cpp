class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // bijection rule basic
        int n = nums.size(); 
        if(n==2){
            if(nums[0]%2==0 && nums[1]%2==0) return 0;
            else if (nums[0]%2!=0 && nums[1]%2!=0) return 0;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]%2==0){
                if(nums[i-1]%2==0 || nums[i+1]%2==0)return 0;
            }
            else{
                if(nums[i-1]%2!=0 || nums[i+1]%2!=0)return 0;
            }
        }
        return 1;
    }
};