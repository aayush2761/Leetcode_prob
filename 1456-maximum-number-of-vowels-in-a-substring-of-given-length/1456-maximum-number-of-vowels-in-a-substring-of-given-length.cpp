// class Solution {
// public:
//     int maxVowels(string s, int k) {
//         int n = s.size();
//         int i=0,j=0;
//         int res=INT_MIN;
//         while(i<n){
//             if(i-j+1==k){
//                 int x=j;
//                 int t=0;
//                 while(x<=i){
//                     if(s[x]=='a'||s[x]=='e'||s[x]=='i'||s[x]=='o'||s[x]=='u') t++;
//                     x++;
//                 }
//                 res=max(t,res);
//                 j++;
//             }
//             i++;
//         }
//         return res;
//     }
// };


class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowel_count = 0;
        int max_vowels = 0;
        
        // Check the first window of size k
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                ++vowel_count;
            }
        }
        max_vowels = vowel_count;
        
        // Slide the window over the rest of the string
        for (int i = k; i < n; ++i) {
            if (isVowel(s[i])) {
                ++vowel_count;
            }
            if (isVowel(s[i - k])) {
                --vowel_count;
            }
            max_vowels = max(max_vowels, vowel_count);
        }
        
        return max_vowels;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
