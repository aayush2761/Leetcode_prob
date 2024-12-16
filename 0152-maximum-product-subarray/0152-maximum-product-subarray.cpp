class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // there is only one negative num 
        double res=-1.0*1e9;
        double mul=1.0;
        // forward
        int n=nums.size();
        for(int i=0;i<n;i++){
            mul*=(double)nums[i];
            res=max(res,mul);
            if(mul==0.0)mul=1.0;
        }
        mul=1.0;
        for(int i=n-1;i>=0;i--){
            mul*=(double)nums[i];
            res=max(res,mul);
            if(mul==0.0)mul=1;
        }
        return (int)res;

    }
};



// [-1,4,-4,5,-2,-1,-1,-2,-3]


// wort time complexity O(n^2)
//  int maxProduct(vector<int>& nums) {
//         double ans=1.0*INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             double temp=(double)nums[i];
//             ans=max(ans,temp);
//             for(int j=i+1;j<nums.size();j++){
//                 temp*=(double)nums[j];
//                 ans=max(ans,temp);
//             }
//         }
//         return (int) ans;
//     }