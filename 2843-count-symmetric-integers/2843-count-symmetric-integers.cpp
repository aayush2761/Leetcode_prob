class Solution {
public:
    int countSymmetricIntegers(int left, int right) {
       int count=0;
       while (left<=right){
      string s = to_string(left);
           int l = s.length();
           int lans=0;
           int rans=0;
           if(l%2==0 ){
               int start=0;
               int e=l-1;
                 while(start<e){
                     lans= lans+(s[start]-'0');
                      rans=rans+(s[e]-'0');
                     start++;
                     e--;
                 }
                 if(lans==rans) count++;
             }
            
            left++;
       }
       return count++;
    }
};