class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return ; 
        unordered_map<int,int>mp;
        for(auto i :  nums) mp[i]++;
       int i=0;
        while (mp[0]) {
            mp[0]--;
            nums[i]=0;
            i++;
        }
        while (mp[1]) {
            mp[1]--;
            nums[i]=1;
            i++;
        }
        while (mp[2]) {
            mp[2]--;
            nums[i]=2;
            i++;
        }


    }
};