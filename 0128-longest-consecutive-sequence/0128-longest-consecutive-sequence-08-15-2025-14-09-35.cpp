class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<1) return 0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int res=1;
        int prev=INT_MIN;
        int count=0;
        for(auto &it : mp){
            if(prev==INT_MIN){
                prev= it.first;
                count=1;
                continue;
            }
            if(prev+1!= it.first){
                count =1;
                prev= it.first;
            }
            else {
                prev= it.first;
                count++;
            }
            res=max(count, res);
        }
        return res;
    }
};