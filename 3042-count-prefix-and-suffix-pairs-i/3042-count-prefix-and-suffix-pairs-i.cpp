class Solution {
public:
    bool solv(string s1, string s2){
        if(s1.size() > s2.size()) 
            return false;
        
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i] || s1[i] != s2[s2.size() - s1.size() + i]) 
                return false;
        }
        
        return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size() - 1; i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(solv(words[i], words[j])) 
                    count++;
                
            }
        }
        return count;
    }
};
