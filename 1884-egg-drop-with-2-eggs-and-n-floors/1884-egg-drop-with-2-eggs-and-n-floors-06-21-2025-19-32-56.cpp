class Solution {
public:
    int twoEggDrop(int n) {
        if(n==1) return 1;
       int x=1;
       int count=1;
       while(count<n){
        int temp = (x*(x+1))/2;
        x++;
        count=temp;
        // cout<<count<<endl;
       }
       return x-1;
    }
};