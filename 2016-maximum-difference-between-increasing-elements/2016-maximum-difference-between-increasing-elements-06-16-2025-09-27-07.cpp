class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n), right(n);
        left[0]=nums[0];
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],nums[i]);
        }
        right[n-1]=nums[n-1];
         for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],nums[i]);
        }
        // 
        int answer=-1;
        if(n==2 ){
            if(nums[0]>=nums[1])return -1;
            return nums[1]-nums[0];
        }
        for(int i=1;i<n;i++){
            if(right[i]-left[i-1]>0){
                answer=max(right[i]-left[i-1],answer);
            }
        }
        return answer;
    }
};