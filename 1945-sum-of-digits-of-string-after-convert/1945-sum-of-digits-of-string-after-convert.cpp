class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(int i=0;i<s.size();i++){
            int t=((s[i]-'a')+1);
            temp += to_string(t);;
        }
        int t=0;
        while(k--){
            int x=0;
            for(int i=0;i<temp.size();i++){
                x+= temp[i]-'0';
            }
            t=x;
            temp= to_string(x);
        }
        return t;
    }
};