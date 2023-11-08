class Solution {
public:
    bool isSameAfterReversals(int num) {
        int ans=0;
        if(num==0) return true;
        if(num%10==0) return false;
        while(num>0){
           ans= ans*10 + num%10;
           num/=10;
        }
        return ans;
    }
};