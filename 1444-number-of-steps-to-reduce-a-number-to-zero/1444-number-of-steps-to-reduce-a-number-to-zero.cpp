class Solution {
public:
    int numberOfSteps(int n) {
        int step=0;
        while(n>0){
             if(n%2==0){
                step=step+1;
                n=n/2;
            }
            else{
                step++;
                n=n-1;
            }
        }
        return step;
    }
};