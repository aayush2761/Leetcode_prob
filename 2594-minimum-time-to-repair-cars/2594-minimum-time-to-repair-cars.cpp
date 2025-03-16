class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long mid) {
        long long temp = 0;
        for (int rank : ranks) {
            temp += (long long)sqrt(mid / rank);
            if (temp >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = 1e15, res = 1e15;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(ranks, cars, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};
