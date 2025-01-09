class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        int x= pref.size();
        for(int i=0;i<words.size();i++){
            string temp= words[i].substr(0,x);
            if(temp==pref)res++;
        }
        return res;
    }
};