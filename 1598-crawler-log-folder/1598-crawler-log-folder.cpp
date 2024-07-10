class Solution {
public:
    int minOperations(vector<string>& logs) {
        int x=0;
        int i=0;
        for(auto i : logs){
            if(i=="../" && x>0) x--;
            else if(i=="./") continue;
            else x++;
           // i++;
        }
        return x;
    }
};