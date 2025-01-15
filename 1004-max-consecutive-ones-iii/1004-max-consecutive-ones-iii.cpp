class Solution {
public:
    int check(int mid, vector<int>& nums, int k, int n) {
        int i = 0, j = 0;
        int oneCount = 0;
        while (i < n) {
            if (nums[i] == 1) oneCount++;
            if (i - j + 1 == mid) {
                int count = mid - oneCount;
                if (count <= k) return 1; // Valid window
                if (nums[j] == 1) oneCount--; // Shrink window
                j++;
            }
            i++;
        }
        return 0;
    }
    int longestOnes(vector<int>& nums, int k) {
       // maximum window size is possible or not 
        // 111111100000000  -> binARY Search 
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        if(n==1 && (nums[0]==1 || k==1))return 1;
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