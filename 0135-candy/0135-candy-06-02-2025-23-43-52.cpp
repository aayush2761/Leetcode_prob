class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,1),right(n,1);
        int answer=0;
        // left to right
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])left[i]= 1+ left[i-1];
        }
        // right to left
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]<nums[i])right[i]= 1+ right[i+1];
        }
        for(int i=0;i<n;i++){
            answer+= max(left[i],right[i]);
        }
        return answer;
    }
};