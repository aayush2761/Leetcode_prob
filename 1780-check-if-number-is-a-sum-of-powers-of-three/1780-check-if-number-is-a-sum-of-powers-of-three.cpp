class Solution {
public:
    vector<long long> three;
    bool recursion(int n, int count, int index) {
        if (count > n) return false;
        if (count == n) return true;
        if (index >= three.size()) return false;

        return recursion(n, count + three[index], index + 1) || recursion(n, count, index + 1);
    }
    bool checkPowersOfThree(int n) {
        if (three.empty()) {
            three.push_back(1);
            for (int i = 1; i < 20; i++) {
                three.push_back(three.back() * 3);
            }
        }
        return recursion(n, 0, 0);
    }
};
