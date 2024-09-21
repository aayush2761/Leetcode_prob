class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>v;
        int i=0;
        while(n>0){
            v.push_back(start +  i*2);
            i++;
            n--;
        }
        int t=0;
        for(auto i : v) t^=i;
        return t;
    }
};