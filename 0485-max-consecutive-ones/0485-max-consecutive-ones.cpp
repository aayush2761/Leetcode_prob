class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int e= nums.size();
        vector<int> v;
        int count =0;
        for(int i=0;i<e;i++ ){
            if(nums[i]==1){
                count++;
            }
            else{
                v.push_back(count);
                count=0;
            }
        }
        v.push_back(count);
        sort(v.begin(),v.end());
        return v[v.size()-1];
    }
};