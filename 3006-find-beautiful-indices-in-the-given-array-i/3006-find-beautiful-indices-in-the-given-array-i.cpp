class Solution {
public:
    void computeZArray(string& s, vector<int>& z) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> res;
        string aa = a + '$' + s; // For Z-array calculation of 'a'
        string bb = b + '$' + s; // For Z-array calculation of 'b'
        int n1 = aa.size(), n2 = bb.size();

        vector<int> da(n1, 0), db(n2, 0);
        computeZArray(aa, da);
        computeZArray(bb, db);

        vector<int> valida, validb;
        for (int i = 0; i < n1; i++) {
            if (da[i] >= a.size()) valida.push_back(i - (a.size() + 1));
        }
        for (int i = 0; i < n2; i++) {
            if (db[i] >= b.size()) validb.push_back(i - (b.size() + 1));
        }

        int i = 0, j = 0;
        while (i < valida.size() && j < validb.size()) {
            if (abs(valida[i] - validb[j]) <= k && valida[i]>=0 && validb[j]>=0) {
                res.push_back(valida[i]);
                i++;
            } else if (valida[i] < validb[j]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};
