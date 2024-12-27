class Solution {
public:
    void zTheorem(string s, vector<int>& z) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]); // Corrected logic
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
    }
    int maxRepeating(string s, string word) {
        s=word+'$'+s;
        vector<int>z(s.size(),0);
        zTheorem(s,z);
        int size=word.size();
        int res=0;
        for(int i=0;i<z.size();i++){
            if(z[i]==size)res++;
            // cout<<z[i]<<" ";
        }
        return res;
    }
};