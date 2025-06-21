class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>result;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<= nums2[j]){
                result.push_back(1.0*nums1[i]);
                i++;
            }
            else {
                result.push_back(1.0*nums2[j]);
                j++;
            }
        }
        while(j<nums2.size()){
                    result.push_back(1.0*nums2[j]);
                    j++;
        }
        while(i<nums1.size()){
                    result.push_back(1.0*nums1[i]);
                    i++;
        }
        int n= result.size();
       if((n)%2)return result[(n)/2];
        return (result[((n)/2)-1] + result[(n)/2]) / 2.0;
    }
};