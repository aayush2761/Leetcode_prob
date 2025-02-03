class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=0;
        int i=1;
        int t=1;
        
        // find increasing
        while(i<nums.size()){
            if(nums[i]>nums[i-1]){
                cout<<nums[i]<<" ";
                 t++;
                  res=max(t,res);
            }
            else{
                res=max(t,res);
                t=1;
            }
            i++;
        }
        cout<<endl;
        i=1,t=1;
         while(i<nums.size()){
            if(nums[i]<nums[i-1]){
                cout<<nums[i]<<" ";
                 t++;
                  res=max(t,res);
            }
            else{
                res=max(t,res);
                t=1;
            }
            i++;
        }
        return res==0 ? 1 : res;
    }
};