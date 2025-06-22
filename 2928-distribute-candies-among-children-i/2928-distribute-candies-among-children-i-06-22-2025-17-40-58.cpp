class Solution {
public:
     
    int distributeCandies(int n, int limit) {
       
        int num = n-(3*limit)+2;
       if(num==1) return 3;
      return(num*num - num)/2;
        
    }
};