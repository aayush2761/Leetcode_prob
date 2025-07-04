class Solution 
{
public:
    char kthCharacter(long long k, vector<int>& operations) 
    {
        // Step 1: Compute final length (2^m)
        long long n = 1;
        int i = 0;
        while (n < k) 
        {
            n <<= 1;
            i++;
        }

        // Step 2: Shift counter
        int d = 0;

        // Step 3: Reverse through operations
        while (n > 1) 
        {
            long long half = n >> 1;
            if (k > half) 
            {
                k -= half; // came from second half
                d += operations[i - 1]; // count shift if op was 1
            }
            
            n = half;
            i--;
        }

        // Step 4: Apply total shift to 'a'
        return 'a' + (d % 26);
    }
};