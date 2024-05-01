class Solution {
public:
    string reversePrefix(string word, char ch) {
       int i=0;
       while(i<word.size()){
        if(word[i]==ch) break;
        i++;
       }
       if(i==word.size()) return word;
       reverse(word.begin(), word.begin() + i + 1);
        
        return word;

    }
};