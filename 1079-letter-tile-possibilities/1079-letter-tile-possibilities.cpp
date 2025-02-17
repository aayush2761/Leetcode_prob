class Solution
{
public:
    int backtrack(unordered_map<char, int>& freqMap){
        int count = 0;
        for (auto& entry : freqMap){
            if (entry.second > 0){
                entry.second--; 
                count += 1 + backtrack(freqMap);  
                entry.second++;
            }
        }

        return count;
    }
    int numTilePossibilities(string tiles){
        unordered_map<char, int> freqMap;
        for (char ch : tiles){
            freqMap[ch]++;
        }
        return backtrack(freqMap);
    }
};