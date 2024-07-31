#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int maxim(const vector<int>& arr, int size) {
        int maxi = INT_MIN;
        int idx = -1;
        for(int i = 0; i <= size; i++) {
            if(maxi < arr[i]) {
                maxi = arr[i];
                idx = i;
            }
        }
        return idx;
    }  
    
    vector<int> pancakeSort(vector<int>& arr) {
        // Find the Maximum Element in the Array
        // Flip the Array to Move the Maximum Element to the Front
        // Flip Again to Move the Maximum Element to Its Correct Position
        // Repeat for the Remaining Unsorted Part of the Array
        int j = arr.size() - 1;
        vector<int> result;
        while(j > 0) {
            int ind = maxim(arr, j);
            if(ind != j) { 
                reverse(arr.begin(), arr.begin() + ind + 1);
                result.push_back(ind + 1);
                reverse(arr.begin(), arr.begin() + j + 1);
                result.push_back(j + 1);
            }
            j--;
        }
        return result;
    }
};
