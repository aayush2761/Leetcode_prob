class Solution {
public:
    int minNumberOfFrogs(string s) {
        unordered_map<char, int> mp;
        mp['c'] = 0;
        mp['r'] = 0;
        mp['o'] = 0;
        mp['a'] = 0;
        mp['k'] = 0;

        int activeFrogs = 0, maxFrogs = 0;

        for (char i : s) {
            if (i == 'c') {
                mp['c']++;
                activeFrogs++;
                maxFrogs = max(maxFrogs, activeFrogs);
            } else if (i == 'r') {
                if (mp['r'] >= mp['c']) return -1;
                mp['r']++;
            } else if (i == 'o') {
                if (mp['o'] >= mp['r']) return -1;
                mp['o']++;
            } else if (i == 'a') {
                if (mp['a'] >= mp['o']) return -1;
                mp['a']++;
            } else if (i == 'k') {
                if (mp['k'] >= mp['a']) return -1;
                mp['k']++;
                activeFrogs--;  // A frog completes croaking.
            }

            // Reset counts if one "croak" sequence is completed.
            if (mp['c'] == mp['r'] && mp['c'] == mp['o'] && mp['c'] == mp['a'] && mp['c'] == mp['k']) {
                mp['c']--;
                mp['r']--;
                mp['o']--;
                mp['a']--;
                mp['k']--;
            }
        }

        // If unbalanced counts remain, return -1.
        if (mp['c'] != mp['r'] || mp['c'] != mp['o'] || mp['c'] != mp['a'] || mp['c'] != mp['k'])
            return -1;

        return maxFrogs;
    }
};
