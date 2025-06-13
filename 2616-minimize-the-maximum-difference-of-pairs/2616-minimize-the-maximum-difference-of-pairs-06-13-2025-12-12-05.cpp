class Solution {
public:
    bool check(int mid,vector<int>&nums, int p){
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=mid) {
                count++;
                i++;
                if(count>=p) return 1;
            }
            // i++;
            
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size(); 
        int low=0, high=nums[n - 1] - nums[0];
        int answer=0;
        while(low<=high){
            int mid= low + (high-low) /2;
            if(check(mid,nums,p)){
                high=mid-1;
                answer=mid;
            }
            else low=mid+1;
        }
        return answer;
    }
};