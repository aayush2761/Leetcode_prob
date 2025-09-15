class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res="";
        map<int,pair<string,int>>mp;
        for(int i=0;i<indices.size();i++){
            int length= sources[i].size();
            // string temp = res.substr(i, length);
             string temp = s.substr(indices[i], length); 
            if(temp == sources[i]){
                mp[indices[i]]= {targets[i], length};
            }
           
        }
        int i=0;
        while(i<s.size()){
            if(mp.count(i)){
                res+= mp[i].first;
                i+= mp[i].second;
            }
            else {
                res+= s[i];
                i++;
            }
        }
        return res;
    }
};