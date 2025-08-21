class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long  ans=0;
        bool neg= false;
        int n = s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            neg= true;
            i++;
        }
        else if(s[i]=='+') i++;
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                ans= (ans*10)+(s[i]-'0');
                if(neg && ans>= INT_MAX) return INT_MIN;
                if(ans>=INT_MAX) return INT_MAX; 
                i++;
            }
            else break;
        }
        if(neg) return (int)((-1.0)*ans);
        return (int)ans;
    }
};