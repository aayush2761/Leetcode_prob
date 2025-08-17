class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sum =0;
        // not equal index and order doesnt matter 
        // sort -----> donot do it oreder matterns 
        // 3000-> we can go upto n^2
        sort(nums.begin(), nums.end());
        // set<vector<int>>st;
         vector<vector<int>>res;

        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l=i+1,r=n-1;
            while(l<r){
                int x=nums[i]+nums[l]+nums[r];
                if(x==0){
                    // st.insert({nums[i],nums[l],nums[r]});
                     res.push_back({nums[i],nums[l],nums[r]});
                    // break;
                    l++;
                    r--;
                    // more possibility
                      // skip duplicate l
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    // skip duplicate r
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(x>0){
                    r--;
                }
                else l++;
            }

        }
        // vector<vector<int>>res;
        // for(auto &it : st){
        //     res.push_back(it);
        // }
        return res;
    }
};