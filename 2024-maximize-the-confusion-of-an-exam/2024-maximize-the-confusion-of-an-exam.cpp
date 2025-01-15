class Solution {
public:
    int check (int mid,string& nums,int k , int n ){
        int i = 0, j = 0, trueCount = 0, falseCount;
        while (i < n) {
            if (nums[i] == 'T') trueCount++;
            else falseCount++;
            if (i - j + 1 == mid) {
                int diff = mid - max(falseCount, trueCount);
                cout<<mid<<":::"<<diff<<endl;
                if (diff <= k) return 1; // Valid window
                if (nums[j] == 'T') trueCount--; // Shrink window
                else falseCount--;
                j++;
            }
            i++;
        }
        return 0;
    }
    int maxConsecutiveAnswers(string nums, int k) {
         // maximum window size is possible or not 
        // 111111100000000  -> binARY Search 
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        int lo = 1;
        int hi = n;
        
        int ans = 0;
        
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