class Solution {
public:
    void zAlgo ( string s, vector<int>&z){
        int n = s.size();
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<r)z[i]= min(r-i, z[i-l]);

            while(i+z[i]<n && s[z[i]]== s[i+z[i]]) z[i]++;
            // boundary 
            if(i+z[i]>r){
                l=i;
                r= i+z[i];
            }
        }
    }
    string longestPrefix(string s) {
        int n = s.size();
        if(n==1) return "";
        vector<int>d(n,0);
        zAlgo(s,d);
        // real 
        string res="";
        for(int i=0;i<d.size();i++){
            if(d[i]>res.size()){
                res= s.substr(i, d[i]);
            }
        }
        if(d[n-res.size()]== res.size()) return res;
       return "";
    }
};