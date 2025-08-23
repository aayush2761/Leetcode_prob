class Solution {
public:
    string reverseWords(string s) {
        vector<string>res;
        stringstream ss(s);
        string tokens="";
        while(getline(ss,tokens,' ')){
            res.push_back(tokens);
        }
       for(int i=0;i<res.size();i++){
             reverse(res[i].begin(), res[i].end());
       }
        string ans="";
       int i=0;
       while(i<res.size()-1){
        ans+= res[i];
        ans+=" ";
        i++;
       }
       ans+=res[i];
       return ans;

    }
};