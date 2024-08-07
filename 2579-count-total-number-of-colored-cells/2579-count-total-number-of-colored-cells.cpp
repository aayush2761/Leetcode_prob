class Solution {
public:
    long long coloredCells(int n) {
        long long res=1;
        int i=1;
        while(n>1){
            res+= 4*i;
            n--;
            i++;

        }
        return res;
    }
};