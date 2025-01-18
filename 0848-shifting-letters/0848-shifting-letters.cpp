class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n= s.size();
        vector<long long >diff(n+1,0);
        for(int i=0;i<shifts.size();i++){
            int left=0;
            int right= i+1;
            diff[left]+=shifts[i];
            diff[right]-=shifts[i];
        }
        // prefixSum
        for(int i=1;i<=n;i++){
            diff[i]+=diff[i-1];
        }
        // for(int i=0;i<diff.size();i++)cout<<diff[i]<<" ";
        // return "";
         for (int i = 0; i < n; i++) {
        char cc = s[i];
         int ci = (cc - 'a' + diff[i]) % 26; 
        if (ci < 0) ci += 26;              
        char res = 'a' + ci;               
        s[i] = res;                       
        }
        return s;
    }
};