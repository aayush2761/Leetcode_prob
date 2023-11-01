class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int e=d.size()-1;
        for(int i=e;i>=0;i--){
            if(d[i]!=9){
                d[i]++;
                return d;
            }
            else{
                d[i]= 0;

            }
        }
        d.insert(d.begin(),1);
        return d;
       }
};