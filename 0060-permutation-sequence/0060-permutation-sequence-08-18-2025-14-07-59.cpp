class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++) {
            string t = to_string(i);
            s+=t;
        }
        // cout<< s;
        if(k==1) return s;
        string t= s;
        while(k>1){
            next_permutation(t.begin(), t.end());
            k--;
        }
        return t;
    }
};