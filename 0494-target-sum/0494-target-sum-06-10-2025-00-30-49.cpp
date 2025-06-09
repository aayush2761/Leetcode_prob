class Solution {
public:
    void solve(vector<int>& nums, int target, int index, int & answer, int temp){
        if(index == nums.size()) {
            if(temp == target) answer++;
            return;
        }
        int x= index;
        solve(nums,target,index+1,answer, temp-nums[x]);
        solve(nums,target,index+1,answer,temp+nums[x]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int answer=0;
        int temp=0;
        solve(nums,target,0,answer,temp);
        return answer;
    }
};