class Solution {
public:
    long long check(int k, string word){
        unordered_map<char,int>mp;
        int consonants=0;
        long long res=0;
        int i=0,j=0;
        while(i<word.size()){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u') mp[word[i]]++;
            else consonants++;
            while(consonants>=k && mp.size()==5){
                res+= word.size()-i;
                if(word[j]=='a'||word[j]=='e'||word[j]=='i'||word[j]=='o'||word[j]=='u') mp[word[j]]--;
                else consonants--;
                if(mp[word[j]]==0)mp.erase(word[j]);
                 j++;
            }
            i++;
        }
        return res;
    }
    long long countOfSubstrings(string word, int k) {
        // atleat k - atleast k+1
        return check(k,word)-check(k+1,word);
    }
};