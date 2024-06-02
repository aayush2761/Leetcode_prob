class Solution {
public:
    void reverseString(vector<char>& s) {
        // by using bit manipulation for  swapping
        int mid= s.size()/2;
        int i=0;
        while(i<mid){
             s[i]= s[i]^ s[s.size()-i-1] ;
             s[s.size()-i-1]= s[i]^ s[s.size()-i-1] ;
             s[i]= s[i]^ s[s.size()-i-1] ;
             i++;
        }
        // return s;
    }
};