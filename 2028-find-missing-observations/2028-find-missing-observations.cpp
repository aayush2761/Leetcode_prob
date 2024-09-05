class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res(n, 1); // Start with all rolls as 1
        int total = accumulate(rolls.begin(), rolls.end(), 0); // Sum of the known rolls
        int num = (n + rolls.size()) * mean; // Total expected sum
        int rem = num - total; // Remaining sum to distribute
        int carry = 0;
        // if(rem % 6 != 0) carry = 1;
        
        if(rem < n || rem > 6 * n) return {}; 

        // for(int i=0; i<n-1; i++){
        //     res.push_back(1);
        //     rem -= 1;
        // }
        // res.push_back(rem);
        
        rem -= n; 

        int i = 0;
        while(rem > 0){
            int add = min(5, rem); 
            res[i % n] += add; 
            rem -= add;
            i++;
        }
        
        return res;
    }
};
