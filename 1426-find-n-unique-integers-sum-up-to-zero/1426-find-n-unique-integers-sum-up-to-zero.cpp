class Solution {
public:
    vector<int> sumZero(int n) {
       
        vector<int>v;
         if(n==0 || n==1) {
             v.push_back(0);
             return v;
         }
        if(n%2==0){
            for(int i=n;i>n/2;i--){
                v.push_back(i);
                v.push_back(-i);

            }
        }
        else {
            v.push_back(0);
            for(int i=1; i<= ceil(n/2);i++){
                v.push_back(i);
                v.push_back(-i);

            }
        }
        return v;
    }
};