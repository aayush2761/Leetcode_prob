class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>st;
        int n =A.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            st.insert(A[i]);
            int temp=0;
            for(int j=0;j<=i;j++){
                if(st.find(B[j])!=st.end())temp++;
            }
            res[i]=temp;
        }
        return res;
    }
};