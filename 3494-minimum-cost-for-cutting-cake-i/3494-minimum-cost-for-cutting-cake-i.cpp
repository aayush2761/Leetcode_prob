class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
                long long hb = 1; // Number of horizontal blocks
        long long vb = 1; // Number of vertical blocks
        long long res = 0; // Result to store the minimum cost

        // Sort the cuts in descending order to always take the largest cut first
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int i = 0, j = 0;

        // Iterate until we have processed all the horizontal and vertical cuts
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                res += horizontalCut[i] * vb; // Add the cost of the horizontal cut
                i++; // Move to the next horizontal cut
                hb++; // Increase the number of horizontal blocks
            } else {
                res += verticalCut[j] * hb; // Add the cost of the vertical cut
                j++; // Move to the next vertical cut
                vb++; // Increase the number of vertical blocks
            }
        }

        // If there are remaining horizontal cuts, process them
        while (i < horizontalCut.size()) {
            res += horizontalCut[i] * vb; // Add the cost of the remaining horizontal cuts
            i++;
        }

        // If there are remaining vertical cuts, process them
        while (j < verticalCut.size()) {
            res += verticalCut[j] * hb; // Add the cost of the remaining vertical cuts
            j++;
        }

        return (int)res;
    }
};