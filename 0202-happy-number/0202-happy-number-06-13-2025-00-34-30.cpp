class Solution {
public:
    bool isHappy(int n) {
        if(n==1) return 1;
        unordered_map<int,int>mp;
        for(int i=0;i<=9;i++)mp[i]= i*i;
        while(n>2){
            int x=0;
            int p=n;
            while(p>0){
                x+= mp[p%10];
                p/=10;
            }
            n=x;
            if(n==1) return 1;
        }
        return 0;
    }
};