class Solution {
public:
     int check(int mid, vector<int>& nums, int k, int n) {
       int i=0,j=0;
          unordered_map<int ,int>mp;
        while(j<nums.size()){
            if(mp[nums[j]]+1>=mid)return true;// all elemets are equal case 
            mp[nums[j]]+=1;
            if(j>= k+mid-1){
                mp[nums[i]]-=1;
                i+=1;
            }
            j++;
        }
        return false;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        // maximum window size is possible or not 
        // 111111100000000  -> binARY Search 
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        int lo = 1;
        int hi = n;
        
        int ans = lo;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid,nums,k,n)){//true
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        
        
        return ans;
    }
};