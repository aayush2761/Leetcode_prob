#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& n, int target) {
        std::vector<int> v;
        std::vector<std::vector<int>> vf;
        int e = n.size() - 1;
        int i = 0;

        std::sort(n.begin(), n.end());  

        while (i <= e - 3) {
            int q = e - 1;
            int j = i + 1;

            while (j < q) {
                int sum = n[i] + n[j] + n[q] + n[e];

                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --q;
                } else {
                    v.push_back(n[i]);
                    v.push_back(n[j]);
                    v.push_back(n[q]);
                    v.push_back(n[e]);
                    vf.push_back(v);
                    v.clear();

                    // Skip duplicates
                    while (j < q && n[j] == n[j + 1]) {
                        ++j;
                    }
                    while (j < q && n[q] == n[q - 1]) {
                        --q;
                    }

                    ++j;
                    --q;
                }
            }

            // Skip duplicates
            while (i <= e - 3 && n[i] == n[i + 1]) {
                ++i;
            }

            ++i;
            --e;
        }

        return vf;
    }
};
