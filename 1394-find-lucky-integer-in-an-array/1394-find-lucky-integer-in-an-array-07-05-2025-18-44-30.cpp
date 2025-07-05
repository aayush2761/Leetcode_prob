class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mp;
        for(auto &it: arr)mp[it]++;
        int answer=-1;
        for(auto &it : mp){
            if(it.first==it.second) answer= max(answer, it.first);
        }
        return answer;
    }
};