class Solution {
public:
    string largestOddNumber(string num) {
        string s=num;
        int i=num.size()-1;
        while(i>=0){
            int t= s[i]-'0';
            if(t%2!=0){
                break;
            }
            else{
                s.erase(i,1);
            }
            i--;
        }
        return s;
    }
};