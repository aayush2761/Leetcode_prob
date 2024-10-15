class Solution {
public:
    long long minimumSteps(string s) {
        long long res=0;
        int n= s.size();
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') count++;
            if(s[i]=='1') {
                res+=count;
            }
        }
        return res;
    }
};