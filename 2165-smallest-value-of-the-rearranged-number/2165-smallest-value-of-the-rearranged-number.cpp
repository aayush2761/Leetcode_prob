class Solution {
public:


    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;  
        }

        long long ans = 0;
        bool neg = false;

        if (num < 0) {
            neg = true;
            num = -num;
        }

        vector<int> temp;

        while (num > 0) {
            temp.push_back(num % 10);
            num /= 10;
        }

        if (neg) {
   
            sort(temp.rbegin(), temp.rend());
        } else {
            sort(temp.begin(), temp.end());

            if (temp[0] == 0) {
                for (int i = 1; i < temp.size(); i++) {
                    if (temp[i] != 0) {
                        swap(temp[0], temp[i]);
                        break;
                    }
                }
            }
        }

        for (auto i : temp) {
            ans = ans * 10 + i;
        }

        return neg ? -ans : ans;
    }
};
