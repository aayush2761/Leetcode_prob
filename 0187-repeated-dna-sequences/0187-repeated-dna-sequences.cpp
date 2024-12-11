class Solution {
public:
    const int mod=1e9+7;
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0,j=0;
        map<string ,int>mp;
        long long count=0;
        while(i<s.size()){
            if(i-j+1==10){
                // mp[count]++;
                string x= s.substr(j,10);
                mp[x]++;
                count-=(s[j]-'A'+1)*pow(10,10);
                j++;
            }
            else{
                i++;
                count= (count*10+(s[i]-'A'+1))%mod;
            }
        }
        vector<string>res;
        for(auto i:mp){
            if(i.second>1) res.push_back(i.first);
        }
        return res;
    }
};