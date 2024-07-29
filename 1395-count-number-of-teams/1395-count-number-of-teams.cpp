#include <vector>

class Solution {
public:
    int numTeams(std::vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;

        // Initialize 3D DP table
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(4, 0)));

        int res = 0;

        for (int i = 0; i < n; ++i) {
            dp[i][0][1] = 1; // Every single element can be the start of an increasing sequence of length 1
            dp[i][1][1] = 1; // Every single element can be the start of a decreasing sequence of length 1

            for (int j = 0; j < i; ++j) {
                if (rating[j] < rating[i]) {
                    for (int k = 1; k < 3; ++k) {
                        dp[i][0][k + 1] += dp[j][0][k];
                    }
                }
                if (rating[j] > rating[i]) {
                    for (int k = 1; k < 3; ++k) {
                        dp[i][1][k + 1] += dp[j][1][k];
                    }
                }
            }

            res += dp[i][0][3] + dp[i][1][3]; // Add all valid sequences of length 3 ending at index i
        }

        return res;
    }
};










//-----------------_____---- RECURSIVE SOLUTIOPN _____------------_***********
// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int res = 0;
//         vector<int> vec;
//         solve(rating, vec, 0, res);
//         return res;
//     }

// private:
//     void solve(vector<int>& rating, vector<int>& vec, int index, int& res) {
//         if (vec.size() == 3) {
//             if ((vec[0] < vec[1] && vec[1] < vec[2]) ||
//                 (vec[0] > vec[1] && vec[1] > vec[2])) {
//                 res++;
//             }
//             return;
//         }

//         for (int i = index; i < rating.size(); ++i) {
//             vec.push_back(rating[i]);
//             solve(rating, vec, i + 1, res);
//             vec.pop_back();
//         }
//     }
// };





// -------- BRUTE FORCE ______---------
// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         // brute force 
//         int res=0;
//         int n = rating.size();
//         for(int i=0;i<n-2;i++){
//             for(int j=i+1;j<n-1;j++){
//                 for(int k=j+1;k<n;k++){
//                     if((rating[i] < rating[j] && rating[j] < rating[k])||
//                     (
//                       rating[i] > rating[j] && rating[j]> rating[k]  
//                     )) res++;
//                 }
//             }
//         }
//         return res;
//     }
// };