class Solution {
public:
    int maximumLength(string s) {
        int res=-1;
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i++){
            string temp="";
            temp.push_back(s[i]);
            mp[temp]++;
            for(int j=i+1;j<s.size();j++){
                temp.push_back(s[j]);
                mp[temp]++;
            }
        }
        for(auto i : mp){
            if(i.second>=3)res=max(res,(int)i.first.size());
        }
        return res;
    }
};