class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); already sorted 
        // same concept as of three sum 
        int ans=0;
        int i=0;
        while(i<nums.size()){
            while(i>0 && i<nums.size() && nums[i]== nums[i-1]){
                // nums.erase(nums[i]);  -> requires the iterator 
                nums.erase(nums.begin()+i);
            }
            ans++;
            i++;
        }
        return ans;
    }
};