class Solution {
public:
    int maxOperations(string s) {
        int i = s.size()-1;

        int count=0;
        int res=0;
        while(i>0){
            if(s[i]=='0' && s[i-1]=='1') count++;
            else if( s[i]=='1' && s[i-1]=='0' || (s[i]=='1' && s[i-1]=='1')) res+=count;
            i--;
        }
        if(s[i]=='1') res+=count;
        return res;
    }
};