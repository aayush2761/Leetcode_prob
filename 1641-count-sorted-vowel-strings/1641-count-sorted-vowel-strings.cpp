class Solution {
public:
    int countVowelStrings(int n) {
        int a =1,e=1,i=1,o=1,u=1;
        while(--n){
            // u will always be one 
            o+=u;
            i+=o;
            e+=i;
            a+=e;
        }
        return a+e+i+o+u;
    }
};