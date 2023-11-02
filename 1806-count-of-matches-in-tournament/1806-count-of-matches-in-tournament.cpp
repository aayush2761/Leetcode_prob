class Solution {
public:
    int matches=0;
    int numberOfMatches(int n) {
        if(n==1) return matches;
        if(n%2==0){
            matches=matches+(n/2);
            numberOfMatches(n/2);
        }
        else{
            matches=matches+(n/2);
            numberOfMatches(n/2 +1);
        }
        return matches;
    }
};