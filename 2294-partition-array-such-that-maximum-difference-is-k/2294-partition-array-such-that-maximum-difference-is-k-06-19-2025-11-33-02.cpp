class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer=0;
        int i=0,j=0;
        while(i<nums.size()){
           if(nums[i]-nums[j]>k){
                answer++;
                j=i;
           }
           i++;
        }
        answer++;
        return answer;
    }
};