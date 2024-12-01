class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<double,int>mp;
        for(auto i : arr){
            if((mp.find((i*2.0))!=mp.end()|| (mp.find(((i*1.0)/2.0))!=mp.end()))) return true;
            mp[(i*1.0)]++;
        }
        return false;
    }
};