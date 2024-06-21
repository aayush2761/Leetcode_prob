class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // code here
        int n=nums.size();
        if(k==n ) return *max_element(nums.begin(), nums.end());
        //sort(nums.begin(), nums.end());
        int m= k;
        if(n<m) return -1;
        int s = 0;
        int e=0;
         e= accumulate(nums.begin(), nums.end(),0);
        int res=-1;
        while(s<=e){
            int mid=s+ (e-s)/2;
            if(isValid(nums,n,m,mid)){
                e=mid-1;
                 res = mid;
            }
            else s=mid+1;
        }
        return res;
    }
private:
   bool isValid( vector<int>& nums,int n, int m , int mid){
        int s=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                s++;
                 if (s > m || nums[i] > mid)
                    return false;
                sum=nums[i];
            }
            
        }
        //if(s>m) return false;
        // int sum=mid;
        // for(auto i:nums){
        //     if(sum>=i) sum-=i;
        //     else{
        //         sum=mid;
        //         s++;
        //         if(sum<i) return 0;
        //         sum-=i;
        //     }
        //     if(s>m) return 0;
            
       // }
        
        return true;
    }
};