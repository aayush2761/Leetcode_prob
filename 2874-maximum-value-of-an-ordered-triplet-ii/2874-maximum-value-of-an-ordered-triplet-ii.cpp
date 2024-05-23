class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        // cal prefix
        prefix[0]=nums[0] ;
        for(int i=1;i<n;i++){
            prefix[i]=max(nums[i],prefix[i-1]); 
        }
        // cal suffix
        suffix[n-1]=nums[n-1]; 
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(nums[i],suffix[i+1]); 
        }

        // calculate answer
        long long answer=0;
        for(int i=1;i<n-1;i++){
            long long temp =(long long) (prefix[i-1] - nums[i]) * suffix[i+1];
            answer= max(answer,temp);
        }
        return answer;
    }
};