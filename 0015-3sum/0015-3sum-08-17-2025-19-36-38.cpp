class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sum =0;
        // not equal index and order doesnt matter 
        // sort 
        // 3000-> we can go upto n^2
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int x=nums[i]+nums[l]+nums[r];
                if(x==0){
                    st.insert({nums[i],nums[l],nums[r]});
                    // break;
                    l++;
                    r--;
                    // more possibility
                }
                else if(x>0){
                    r--;
                }
                else l++;
            }

        }
        vector<vector<int>>res;
        for(auto &it : st){
            res.push_back(it);
        }
        return res;
    }
};