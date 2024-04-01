class Solution {
public:
    int lengthOfLastWord(string s) {
        int e= s.length()-1;
        int count=0;
         while (e >= 0 && s[e] == ' ') {
            e--;
        }
      
        for(int i=e;i>=0;i--){
            if(s[i]==' ') break;
            count++;
        }
        return count;
    }
};