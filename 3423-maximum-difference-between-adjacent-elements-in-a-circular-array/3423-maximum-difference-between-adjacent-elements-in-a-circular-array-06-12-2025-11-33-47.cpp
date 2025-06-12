class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.push_back(nums[0]);
        int answer=0;
        for(int i=1;i<nums.size();i++){
            answer= max(answer,abs( nums[i]-nums[i-1]));
        }
        return answer;
    }
};