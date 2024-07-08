class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<double,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            // cal the res 
            double temp=0;
            for(int j=0;j<strs[i].size();j++){
                temp+= 1.0*(strs[i][j]-'0');
            }
            mp[temp].push_back(strs[i]);
        }
        // answer
        vector<vector<string>> res;
        for(auto i : mp){
            res.push_back(i.second);
        }
        return res;
    }
};