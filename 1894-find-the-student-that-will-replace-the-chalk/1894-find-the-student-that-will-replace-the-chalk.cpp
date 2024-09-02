class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        int n = chalk.size();
        
        // Calculate the total amount of chalk required for one full pass
        for (int i = 0; i < n; ++i) {
            totalChalk += chalk[i];
        }
        
        // Reduce k to a more manageable number
        k %= totalChalk;
        
        // Find the student who will not get enough chalk
        for (int i = 0; i < n; ++i) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1; // This line is technically unreachable
    }
};
