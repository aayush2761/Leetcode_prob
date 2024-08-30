// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         int i = 0;
//         int total = 0;

//         // Determine the correct row 'i'
//         while (i < n) {
//             if (total + m < k) {
//                 total += m;
//                 i++;
//             } else {
//                 break;
//             }
//         }

//         // Calculate the column index 'jj' in row 'i'
//         int jj = k - total - 1;

//         return matrix[i][jj];
//     }
// };
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        
        for (int i = 0; i < n; i++) {
            minHeap.push({matrix[i][0], i, 0});
        }

        while (k > 1) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            int row = curr[1], col = curr[2];
            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
            k--;
        }

        return minHeap.top()[0];
    }
};