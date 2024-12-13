class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string x=s;
        for(int i=0;i<s.size()-1;i++){
            // rotate brohhh!!!
            string temp=x.substr(1)+x[0];
            // cout<<temp<<endl;
            if(temp==s)return true;
            x=temp;
        }
        return false;
    }
};