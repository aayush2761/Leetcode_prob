class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        double temp = 0.0;

        while (i < k) {
            temp += nums[i];
            i++;
        }
        
        double res = temp / k;

        // Slide the window over the rest of the array
        while (i < nums.size()) {
            temp += nums[i];
            temp -= nums[j];
            j++;
            i++;
            double x = temp / k;
            res = max(res, x);
        }
        
        return res;
    }
};
