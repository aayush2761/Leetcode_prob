

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end());
        int size = happiness.size();

        long long answer = 0;
        int i = k - 1; // Start from k-1 to 0

        while (k > 0 && i >= 0) {
            int p = size - 1 - i; // Calculate the index from the end
            if (p >= 0 && happiness[p] - i >= 0) {
                answer += (happiness[p] - i);
            }
            k--; // Decrease k
            i--; // Decrease i
        }

        return answer;
    }
};

