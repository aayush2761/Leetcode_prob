class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>keysIndices;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key) keysIndices.push_back(i);
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<keysIndices.size();j++){
                if(abs(keysIndices[j]-i)<=k){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};