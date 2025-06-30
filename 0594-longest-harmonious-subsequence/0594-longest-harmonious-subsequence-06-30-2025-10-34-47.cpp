class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        int answer=0;
        for(auto &it : nums) mp[it]++;
        for(auto &it : mp){
            if(mp.find(it.first+1)!= mp.end()){
                answer= max(answer, it.second+ mp[it.first+1]);
            }
        }
        return answer;
    }
};