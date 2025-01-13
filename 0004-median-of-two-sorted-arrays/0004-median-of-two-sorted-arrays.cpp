class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<double>vec;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            double a = 1.0*nums1[i];
            double b = 1.0*nums2[j];
            if(a>=b){
                vec.push_back(b);
                j++;
            }
            else {
                vec.push_back(a);
                i++;
            }
        }
        while(i<nums1.size()){
            vec.push_back(1.0*nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            vec.push_back(1.0*nums2[j]);
            j++;
        }

        if((n+m)%2)return vec[(n+m)/2];
        return (vec[((n+m)/2)-1] + vec[(n+m)/2]) / 2.0;
       
       

    }
};