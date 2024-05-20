class Solution {
public:
    vector<int>v;
    void superSubSets( vector<vector<int>>&answer,vector<int>& nums,int index){
        if(index== nums.size()){
             answer.push_back(v);
             return;
        }
         v.push_back(nums[index]) ;
          superSubSets(answer,nums,index+1);
         v.pop_back() ;
         superSubSets(answer, nums, index+1);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answer;
        int index=0;
         superSubSets(answer,nums,index);
         return answer;
    }
};