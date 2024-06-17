class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        if(c==1) return true;
        int initial =0;
        int last=sqrt(c);
        int temp=0;
        while(initial<=last){
            if(((long long )initial*initial + (long long ) last*last) >=INT_MAX){
                last-=1;
                continue;
            }
            temp= initial*initial +  last*last;
            if(temp>c ) last-=1;
            else if(temp<c) initial+=1;


            if(temp==c) return true;
          
        }
          if(temp==c) return true;
        return false;
    }
};