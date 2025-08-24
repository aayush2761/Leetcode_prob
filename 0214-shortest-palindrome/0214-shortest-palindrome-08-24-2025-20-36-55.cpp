class Solution {
public:
    void zAlgo(string s, vector<int>&z){
        int l=0, r=0;
        for(int i=1; i<s.size(); i++){
            if(i < r) 
                z[i] = min(r - i , z[i - l]);
            while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]) 
                z[i]++;
            if(i + z[i]  > r){
                l = i;
                r = i + z[i] ;
            }
        }
    }

    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + '#' + rev_s;

        int n = new_s.size();
        vector<int> z(n,0);
        zAlgo(new_s, z);

        int longest = 0;
        for(int i = s.size()+1; i < n; i++){
            if(z[i] == n - i){
                longest = z[i]; 
                break;  
            }
        }

        string add = s.substr(longest);
        reverse(add.begin(), add.end());
        return add + s;
    }
};
