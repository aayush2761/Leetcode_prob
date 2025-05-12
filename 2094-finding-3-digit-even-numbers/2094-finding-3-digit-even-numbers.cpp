class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;
        int n= digits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k && digits[i]!=0){
                        int x = 100*digits[i] + 10 * digits[j] + digits[k];
                       if ((x & 1) == 0) st.insert(x);
                    }
                }
            }
        }
        vector<int>res;
         for(auto it = st.begin(); it!=st.end();it++)res.push_back(*it);
          return res;
    }
};