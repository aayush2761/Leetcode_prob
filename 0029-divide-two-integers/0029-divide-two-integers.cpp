class Solution {
public:
    int divide(int dd, int dr) {
        if (dr != 0) {
           
            if (dd == INT_MIN && dr == -1) {
                return INT_MAX;
            }
            
            long long dividend = static_cast<long long>(dd);
            long long divisor = static_cast<long long>(dr);
            
            long long ans = dividend / divisor;

           
            if (ans > INT_MAX) {
                return INT_MAX;
            } else if (ans < INT_MIN) {
                return INT_MIN;
            } else {
                return static_cast<int>(ans);
            }
        }
        return INT_MAX; 
    }
};
