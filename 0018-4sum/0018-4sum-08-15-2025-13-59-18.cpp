using ll= long long;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //  array of all the ((([[[unique quadruplets]]]))) 
        // index doesnot matters 
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        int n = nums.size();
        if(n<4) return {};
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    // binary search for the remaining 
                    int l= k+1, h= n-1;
                    while(l<=h){
                        int mid = l +(h-l) /2;
                        long long temp= (ll)nums[i]+(ll)nums[j]+(ll)nums[k]+(ll)nums[mid];
                        if(temp==(long long)target) {
                            st.insert({nums[i],nums[j],nums[k], nums[mid]});
                            l=mid+1;
                        }
                        else if(temp<target) l=mid+1;
                        else h= mid-1;
                    }
                }
            }
        }
        for(auto &it :st) ans.push_back(it);
        return ans;
    }
};