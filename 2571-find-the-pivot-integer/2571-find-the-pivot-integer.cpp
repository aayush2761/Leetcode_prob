class Solution {
public:
     int pivotInteger(int n) {
         if(n==1) return 1;
        int mid=n/2;
        while(mid<=n){
            int countb =0;
            int afterb =0;
            for(int i=mid;i<=n;i++){
                afterb=afterb+i;
            }
            for(int i=1;i<=mid;i++){
                countb=countb+i;
            }
            if(countb==afterb) {
                return mid;
                
            }
            mid++;

        }
        return -1;
    }
};

