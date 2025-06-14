class Solution {
public:
    int minMaxDifference(int num) {
        string t= to_string(num);
        char c;
        for(int  i=0;i<t.size();i++){
            if(t[i]<'9'){
                c=t[i];
                break;
            }
        }
        // char c= t[0];
        string s=t;
        for(int i=0;i<t.size();i++){
            if(t[i]==c) t[i]='9';
        }
        char c1;
        for(int  i=0;i<t.size();i++){
            if(s[i]!='0'){
                c1=s[i];
                break;
            }
        }
        for(int i=0;i<t.size();i++){
            if(s[i]==c1) s[i]='0';
        }
        return stoi(t)-stoi(s);
    }
};