class Solution {
public:
    string rle(string s){
        string res="";
        int i=0,j=0;
        int n= s.size();
        while(i<s.size()){
            while(i+1<n && s[i]==s[i+1]){
                i++;
            }
            int x= i-j+1;
            res+= to_string(x) + s[j];
            j=i+1;
            i++;
        }
        return res;
    }
    string countAndSay(int n) {
        string ans= "1";
        if(n==1) return ans;
        while(n>1){
            ans= rle(ans);
            n--;
        }
        return ans;
    }
};