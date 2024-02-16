class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int p =max(cost1,cost2);
        int q= min(cost1,cost2);
        if(cost1>total && cost2>total) return 1;
        if(cost1<total && cost2>total) return total/cost1 +1;
         if(cost2<total && cost2>total) return total/cost2 +1;
        long long ans=0;
        int r= total/p;
        int i=0;
        while(i<=r){
            //ans+=1;
            long long x= total;
            x-= p*i;
            if(x>0) ans+= (x/q +1);
            else{
                ans+=1;
            }
            i++;
        }
        return ans;
    }
};