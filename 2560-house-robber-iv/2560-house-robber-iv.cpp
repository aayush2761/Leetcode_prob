class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // min max -> binay search 
        // why not dp -> 4 variables into the states not possible 
        if(k==1){
            return *min_element(nums.begin(),nums.end());
        }
        int n = nums.size();
        vector<int>mini(n);
        mini[n-1]=nums[n-1];
        int least= mini[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=min(least, nums[i]);
            least= min(least,nums[i]);
        }
        int res=INT_MAX;
        for(int i=0;i<n-k;i++){
            int t= max(nums[i], mini[i+k]);
            res=min(t,res);
        }
        return res;
    }
};