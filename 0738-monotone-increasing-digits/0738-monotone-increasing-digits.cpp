class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s= to_string(n);
        int e= s.size()-1;
        if(s.size()==1) return n;
        int p=e+1;
        for(int i=e;i>0;i--){
            if(s[i-1]>s[i]){
                p=i;
                    s[i-1]=s[i-1]-1;
            }
        }
        for(int i= p;i<=e;i++){
            s[i]='9';
        }
        return stoi(s);
    }
};