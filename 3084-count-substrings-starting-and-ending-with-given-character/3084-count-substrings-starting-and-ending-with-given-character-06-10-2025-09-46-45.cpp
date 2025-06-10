class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count=0;
        for(auto & it : s){
            if(it==c)count++;
        }
        int x= count+1;
        if(count&1)x/=2;
        else count/=2;
        return (long long)count* (long long)x;
    }
};