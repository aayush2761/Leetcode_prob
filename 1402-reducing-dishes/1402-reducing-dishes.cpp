class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int res = 0, currentSum = 0, total = 0;

        for (int i = n - 1; i >= 0; i--) {
            currentSum += satisfaction[i];
            total += currentSum;
            res = max(res, total);
        }
        return res;
    }
};
