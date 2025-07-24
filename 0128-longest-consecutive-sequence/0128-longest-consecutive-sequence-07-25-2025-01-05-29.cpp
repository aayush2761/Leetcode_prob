class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int answer=1;
        int temp=1;
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]== nums[i-1]){
                continue;
            }
            if(nums[i]==  nums[i-1]+1) temp++;
            else temp=1;
            answer= max(temp,answer);
        }
        return answer;
    }
};