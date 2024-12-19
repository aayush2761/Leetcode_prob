class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int req) {
        int count = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i] == 0 && (i == 0 || v[i - 1] == 0) && (i == n - 1 || v[i + 1] == 0)) {
                v[i] = 1;
                count++;
            }
            if (count >= req) {
                return true;
            }
        }
        return count >= req;
    }
};
