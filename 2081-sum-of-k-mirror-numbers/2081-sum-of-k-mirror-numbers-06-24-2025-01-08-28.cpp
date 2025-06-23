class Solution {
public:
bool palindrome(string &s){
    int i=0, j= s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
    string convertToBase(int k, int n ){
        string res="";
        while(n>0){
            res.push_back(n%k);
            n/=k;
        }
        return res;
    }
    long long kMirror(int k, int n) {
        int i=1;
        long long answer=0LL;
        while(i<100000001 && n>0){
            string num = to_string(i);
            string converted= convertToBase(k,i);
            if(palindrome(num) && palindrome(converted)){
                answer+= i;
                n--;
            }
            i++;
        }
        return answer;
    }
};