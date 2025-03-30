class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int>res;
        int prevIndex=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            prevIndex= max(mp[s[i]], prevIndex);
            if(i==prevIndex){
                res.push_back(i+1-j);
                j=i+1;
            }
        }
        return res;
    }
};