class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            string temp="";
            for(auto& i : words[i]){
                temp+=i;
                mp[temp]++;
            }
        }
        vector<int>res;
         for(int i=0;i<words.size();i++){
            string temp="";
            int r=0;
            for(auto& i : words[i]){
                temp+=i;
                r+= mp[temp];
            }
            res.push_back(r);
        }
        return res;
    }
};