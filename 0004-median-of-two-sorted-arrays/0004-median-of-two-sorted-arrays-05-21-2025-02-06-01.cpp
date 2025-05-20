class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                 res.push_back(nums2[j]);
                j++;
            }
           
        }
         while(j<nums2.size()){
                    res.push_back(nums2[j]);
                    j++;
        }
         while(i<nums1.size()){
                    res.push_back(nums1[i]);
                    i++;
                }
        int n = res.size();
        double ans=0.0;
         if(n&1){
            ans= 1.0*res[(n/2)];
         }
         else {
             ans = (res[n/2 - 1] + res[n/2]) / 2.0;
         }
         return ans;
    }
};