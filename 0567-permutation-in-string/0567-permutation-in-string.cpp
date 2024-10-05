class Solution {
public:
    bool arePermutations(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) return false;
    int charCount[256] = {0}; 
    for (char c : str1) {
        charCount[c]++;
    }
    for (char c : str2) {
        charCount[c]--;
        if (charCount[c] < 0) return false;
    }

    return true;
}
    bool checkInclusion(string s1, string s2) {
        int s = s1.size();
        int i=0,j=0;
        while(i<s2.size()){
        
            if(i-j+1==s){
                string temp= s2.substr(j,s);
                j++;
                // cout<<temp<<endl;
                if(arePermutations(temp, s1)) return true;
                
            }
            i++;
        }

        return false;
    }
};