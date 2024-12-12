class Solution {
public:
    string longestPrefix(string s) {
        unordered_map<string,int>mp;
        int n= s.size();
        for(int i=1;i<n;i++){
            string x=s.substr(0,i);
            mp[x]++;
        }
        string res="";
        for(int i=n-1;i>0;i--){
            string x=s.substr(i);
            if(mp.find(x)!=mp.end() && res.size()<=x.size())res=x;
        }
        
        // for(auto i:mp){
        //     if(i.second==2 && i.first.size()>=res.size()) res=i.first;
        // }
        return res;

    }
};