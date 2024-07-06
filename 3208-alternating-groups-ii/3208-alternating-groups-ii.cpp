class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res=0;
        int i=1,windowSize=1;
        int n = colors.size();
        while(i<=n+k-2){
            if(colors[i%n]!=colors[(i-1+n)%n ]){
                windowSize++;
            }
           else windowSize=1;
            if(windowSize>=k) res++;
            i++;
        }
        return res;
    }
};