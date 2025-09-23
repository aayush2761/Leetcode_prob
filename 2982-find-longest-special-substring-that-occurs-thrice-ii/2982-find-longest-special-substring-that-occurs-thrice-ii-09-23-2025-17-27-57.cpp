class Solution {
public:
    bool single(string s){
        for(int i=1;i<s.size();i++){
            if(s[i] != s[0]) return false;
        }
        return 1;
    }
    bool check(int k, string &s){
        // map<string,int>mp;
        // for(int i=0;i<=s.size()-mid;i++){
        //     string temp = s.substr(i,mid);
        //     mp[temp]++;
        //     // if(mp[temp]>=3) return true;   -> single character repeat hona chaiye yr 
        //     if(mp[temp]>=3 && single(temp)) return true;
        // }
        // return false;
        int n = s.size();
        vector<int> charFreq(26, 0); // Vector to store character frequencies

        int i = 0, j = 0;
        int distinctChars = 0;
        vector<int> charFreqTwiceOrMore(26, 0); // Vector to track characters occurring twice or more

        while (j < n) {
            // Update frequency for the current character in the substring
            charFreq[s[j] - 'a']++;

            // Check if the current character is encountered for the first time in the window
            if (charFreq[s[j] - 'a'] == 1) {
                distinctChars++; // Increment distinct character count
            }

            // Check if the window size is 'k'
            if (j - i + 1 == k) {
                // If there's only one distinct character in the window
                if (distinctChars == 1) {
                    charFreqTwiceOrMore[s[j] - 'a']++;
                    // If this character appears three or more times, return true
                    if (charFreqTwiceOrMore[s[j] - 'a'] >= 3) {
                        return true;
                    }
                }
                // Move the window by incrementing 'i'
                charFreq[s[i] - 'a']--;
                if (charFreq[s[i] - 'a'] == 0) {
                    distinctChars--; // Decrement distinct character count
                }
                i++; // Move the window start pointer
            }
            j++; // Move the window end pointer
        }

        return false; // Return false if no valid substring found
    }
    int maximumLength(string s) {
        int ans=-1;
        int n = s.size();
        int low=1, high= n-2;
        while(low<=high){
            int mid = low + (high-low) /2;
            if(check(mid,s)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans==0 ? -1 : ans;
    }

};