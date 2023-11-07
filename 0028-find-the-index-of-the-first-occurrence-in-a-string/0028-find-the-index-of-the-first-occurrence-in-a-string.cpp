/*class Solution {
public:
    int strStr(string haystack, string needle) {
        int e= haystack.size();
        int k=needle.size();
        string s;
        int count=0;
        if(e==1) return 0;
        for(int i=0;i<e-k;i++){
            int j;
            int m=i;
            for(j=0;j<k;j++){
               
               if (haystack[i + j] != needle[j]) {
                    break;
                }
               
            }
             if(j==k) return i;
        }
        return -1;
    }
};*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        
        if (nlen == 0) {
            return 0;  // Empty needle is always found at the beginning.
        }
        
        if (hlen < nlen) {
            return -1; // Cannot find needle if haystack is shorter than needle.
        }

        for (int i = 0; i <= hlen - nlen; i++) {
            int j;
            for (j = 0; j < nlen; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            
            if (j == nlen) {
                return i;  // Found a match; return the starting index.
            }
        }
        
        return -1; // Needle not found in haystack.
    }
};
