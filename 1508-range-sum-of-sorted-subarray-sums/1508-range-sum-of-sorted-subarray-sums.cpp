class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            int count= nums[i];
            res.push_back(count);
            for(int j=i+1;j<nums.size();j++){
                count+= nums[j];
                 res.push_back(count);
            }
        }
        sort(res.begin(),res.end());
        int t=0;
        l-=1;
        r-=1;
        while(l<=r){
            t+=res[l];
            l++;
        }
        return t;
    }
};