class Solution {
public:
    string reverseWords(string s) {
        vector<string>store;
        stringstream ss(s);
        string token="";
        while(getline(ss,token,' ')){
            if(!token.empty())store.push_back(token);
        }
        int i=0,j= store.size()-1;
        while(i<=j){
            swap(store[i], store[j]);
            i++;
            j--;
        }
        string res="";
        for(auto &it: store){
            res+= it;
            res+=" ";
        }
        i=0;
        j= res.size()-1;
        while(res[i]==' ') i++;
        while(res[j]==' ')j--;
        res= res.substr(i, j-i+1);
        return res;
    }
};