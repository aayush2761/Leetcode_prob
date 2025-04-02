class Solution {
public: 
   
    long long maximumTripletValue(vector<int>& nums) {
         int n= nums.size();
        long long answer=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long x=(long long)(nums[i] - nums[j]) * nums[k];
                    if(x<0) x=0;
                    answer= max(x,answer);
                }
            }
        }
        return answer;
    }
    
};