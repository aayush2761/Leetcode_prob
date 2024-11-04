class Solution {
public:
    string compressedString(string s) {
        string res="";
        int i=0;
        while(i<s.size()){
            int x=1;
            while(i+1<s.size() && s[i]==s[i+1]){
                x++;
                i++;
                if(x==9) break;
            }
            res+=to_string(x);
            res+=s[i];
            i++;
        }
        return res;
    }
};