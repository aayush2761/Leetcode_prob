class Solution {
public:
    double med(int n ,int m,  vector<int>& nums1, vector<int>& nums2){
         int low =0 , high= n; // n-> nums1 wala chota 
         bool odd= false;
         if((n+m )%2!=0) odd= true;
         while(low<=high){
            int midx = low + (high-low)/2;
            int midy = (n + m + 1) / 2 - midx;

            int left1 = (midx == 0) ? INT_MIN : nums1[midx - 1];
            int left2 = (midy == 0) ? INT_MIN : nums2[midy - 1];

            int right1 = (midx == n) ? INT_MAX : nums1[midx];
            int right2 = (midy == m) ? INT_MAX : nums2[midy];

            if(left1<= right2 && left2<= right1){
                if(odd) return double(max(left1, left2));
                else return double((max(left1,left2) + min(right1, right2)) / 2.0);
            }
            else if(left1>right2)high=midx-1;
            else low= midx+1;
         }
         return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int  m = nums2.size();
        if(n==0){
            if(m&1){
                return double(nums2[m/2]);
            }
            else return double((nums2[m/2] + nums2[(m/2) -1])/2.0);
        }
        else if(m==0){
            if(n&1){
                return double(nums1[n/2]);
            }
            else return double((nums1[n/2] + nums1[(n/2) -1])/2.0);
        }
        // code 

        if(n > m) return med(m, n, nums2, nums1);
        return med(n, m, nums1, nums2);
    }
};