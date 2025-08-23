class Solution {
public:
    string defangIPaddr(string address) {
        vector<string>ans;
        stringstream ss(address);
        string token="";
        while(getline(ss,token,'.')){
            ans.push_back(token);
        }
        string res="";
        for(int i=0;i<ans.size()-1;i++){
            res+= ans[i];
            res+="[.]";
        }
        res+=ans[ans.size()-1];
        return res;
    }
};