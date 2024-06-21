class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int zeroSum = 0;
        int maxExtra = 0;
        int currentExtra = 0;
        
        // Calculate the base satisfaction where grumpy[i] == 0
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                zeroSum += customers[i];
            }
        }

        // Calculate the initial extra satisfaction for the first window
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentExtra += customers[i];
            }
        }
        maxExtra = currentExtra;

        // Use sliding window to find the maximum extra satisfaction
        for (int i = minutes; i < customers.size(); ++i) {
            if (grumpy[i] == 1) {
                currentExtra += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentExtra -= customers[i - minutes];
            }
            maxExtra = max(maxExtra, currentExtra);
        }

        return zeroSum + maxExtra;
    }
};
