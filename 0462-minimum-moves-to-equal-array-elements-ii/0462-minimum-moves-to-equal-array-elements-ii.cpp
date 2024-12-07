class Solution {
public:
    int minMoves2(vector<int>& nums) {
         int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());
        long long res=LLONG_MAX;
        while(left<=right){
            int mid= left+ (right-left) /2;
            // cost 
            long long temp=0;
            for(int i=0;i<nums.size();i++){
                temp+=((long long)abs(nums[i]-mid));
            }
            res=min(temp,res);
            // direction 
            long long temp1=0;
            for(int i=0;i<nums.size();i++){
                temp1+=((long long)abs(nums[i]-mid-1));
            }
            res=min(temp1,res);
            if(temp1<=temp){
                
                left=mid+1;
            }
            else right=mid-1;
        }
        return (int)res;
    }
};