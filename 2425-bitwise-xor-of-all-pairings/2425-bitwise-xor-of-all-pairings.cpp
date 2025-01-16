class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x=0;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1%2)for(auto i : nums2) x^=i;
        int res=0;
        if(n2%2)for(auto i: nums1) res^=(i);
        return res^x;
    }
};