#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); ++i) {
            bool isUnique = true;
            for (int j = 0; j < s.size(); ++j) {
                if (i != j && (s[i] ^ s[j]) == 0) {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique) {
                return i;
            }
        }

        return -1;
    }
};
