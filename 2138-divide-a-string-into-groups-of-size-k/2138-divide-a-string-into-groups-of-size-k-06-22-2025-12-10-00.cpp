class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int rem = k- n%k;
         vector<string>res;
         int i=0;
         while(i<n){
            string temp = s.substr(i,k);
            i+=k;
            res.push_back(temp);
         }
         if(n%k==0)return res;
         i-=k;
         while(rem--){
            res[res.size()-1]+=fill;
         }
          return res;
    }
};