class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int x = nums[i]*nums[j];
                if(mp.find(x)!=mp.end()){
                    res+= 8*mp[x];
                    mp[x]++;
                }
                else mp[x]++;
            }
        }
        return res;

    }
};