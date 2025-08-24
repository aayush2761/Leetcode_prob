class Solution {
public:
    void zAlgo(string s, vector<int>&z){
        int l=0,r=0;
        for(int i=1;i<s.size();i++){
            if(i<r) z[i]= min(r-i, z[i-l]);
            // extension 
            while(z[i]+i<s.size() && s[z[i]]==s[i+z[i]]) z[i]++;
            // boundary 
            if(i+z[i]>r){
                l=i;
                r= i+z[i];
            }
        }
    }
    int strStr(string haystack, string needle) {
        string temp= needle+'$'+haystack;
        int n= temp.size();
        vector<int>z(n,0);
        zAlgo(temp,z);
        for(int i=0;i<n;i++){
            if(z[i]==needle.size()){
                return i-z[i]-1;
            }
        }
        return -1;
    }
};