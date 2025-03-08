class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res=INT_MAX;
        int temp=0;
        int i=0,j=0;
        int count=0;
        while(i<blocks.size()){
            temp+=1;
            if(blocks[i]=='W')count++;
            while(temp==k && j<=i){
                // if(temp==k){
                    res=min(res,count);
                // }
                temp-=1;
                if(blocks[j]=='W')count--;
                j++;
            }
            i++;
        }
        return res==INT_MAX? 0 : res;
    }
};