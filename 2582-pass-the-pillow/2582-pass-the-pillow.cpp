class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1;
        bool flag=true;
        while(time>0){
            if(flag){
                i++;
            }
            else if(!flag)i--;

            if(i==n) flag=false;
            if(!flag && i==1) flag=true;
            time--;
        }
        return i;
    }
};