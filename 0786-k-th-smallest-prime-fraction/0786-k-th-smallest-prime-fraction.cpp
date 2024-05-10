class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map< double,vector<int>> mp; // Use double for accurate fraction representation
        int n = arr.size();

        // Generate all unique pairs (arr[j], arr[i]) with j < i
        for (int j = 0; j < n - 1; ++j) {
            for (int i = j + 1; i < n; ++i) {
                vector<int> fraction = {arr[j], arr[i]};
                double value = (double)arr[j] / arr[i]; // Calculate the fraction value

                mp[value] = fraction; // Store the fraction and its value in the map
            }
        }

        int l = 1;
        // Traverse the map to find the k-th smallest fraction
        for (auto& p : mp) {
            if (l == k) {
                return p.second; // Return the fraction (pair) when found
            }
            l++;
        }

        return {}; // Return empty vector if k-th smallest fraction is not found (shouldn't happen)
    }
};