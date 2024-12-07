class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());
        long long res=LLONG_MAX;
        while(left<=right){
            int mid= left+ (right-left) /2;
            // cost 
            long long temp=0;
            for(int i=0;i<nums.size();i++){
                temp+=((long long)abs(nums[i]-mid)*(long long)cost[i]);
            }
            res=min(temp,res);
            // direction 
            long long temp1=0;
            for(int i=0;i<nums.size();i++){
                temp1+=((long long)abs(nums[i]-mid-1)*(long long)cost[i]);
            }
            res=min(temp1,res);
            if(temp1<=temp){
                
                left=mid+1;
            }
            else right=mid-1;
        }
        return res;
    }
};


// class Solution {
// public:
//     long long minCost(vector<int>& nums, vector<int>& cost) {
//         long long res=INT_MAX;
//         for(int i=0;i<nums.size();i++){
//             long long c=0;
//             for(int j=0;j<nums.size();j++){
//                 if(nums[i]==nums[j]) continue;
//                 // cout<<"o"<<endl;
//                 c+=(abs(nums[i]-nums[j]))*cost[j];
//                 cout<<c<<endl;
//             }
//             res=min(c,res);
//         }
//         return res;
//     }
// };