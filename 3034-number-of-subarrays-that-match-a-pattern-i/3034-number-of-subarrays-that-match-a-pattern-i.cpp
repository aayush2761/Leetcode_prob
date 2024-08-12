class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        // int psize = pattern.size()+1;
        int res=0;
        for(int i=0;i<nums.size()-pattern.size();i++){
            bool flag= true;
            for(int k=0;k<pattern.size();k++){
                  if(pattern[k]==0){
                      if(nums[i + k + 1] != nums[i + k]){
                           flag= false;
                          break;
                      }
                  }
                  else if(pattern[k]==1){
                      if(nums[i + k + 1] <= nums[i + k]){
                           flag= false;
                          break;
                      }
                  }
                  else if(pattern[k]==-1){
                      if(nums[i + k + 1] >= nums[i + k]) {
                           flag= false;
                          break;
                      }
                  }                   
             }
              if(flag) res++;
         }
        return res;
    }

};