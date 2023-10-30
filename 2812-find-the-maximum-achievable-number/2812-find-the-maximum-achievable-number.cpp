class Solution {
public:
    int theMaximumAchievableX(int n, int t) {
        int x=n+ 2*t ;
        /*int count=0;
        for(int i=0;i<t;i++){
            if(x<=n){
                x++;
                n--;
                count ++;
            }
            else{
                x--;
                n++;
                count ++;
            }
        }
        return count;*/
        return x;
        
    }
};